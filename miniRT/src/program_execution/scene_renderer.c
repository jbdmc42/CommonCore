#include "../../include/minirt.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <X11/Xlib.h>

/* MiniLibX Linux stores these native handles as the first struct members. */
typedef struct s_mlx_display_prefix
{
	Display	*display;
}	t_mlx_display_prefix;

typedef struct s_mlx_window_prefix
{
	Window	window;
}	t_mlx_window_prefix;

static int	render_image(t_data *data);

static int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_loop_end(data->mlx.mlxcon);
	return (S);
}

// Function that puts the already-rendered img back into window after
//  minimizing or maximizing, uncovered or resized
static int	expose_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!data || !data->mlx.mlxcon || !data->mlx.window || !data->mlx.image)
		return (E);
	mlx_put_image_to_window(data->mlx.mlxcon, data->mlx.window,
		data->mlx.image, 0, 0);
	return (S);
}

static int	focus_window(int button, int x, int y, void *param)
{
	t_data	*data;
	t_mlx_display_prefix	*mlx;
	t_mlx_window_prefix		*window;

	(void)button;
	(void)x;
	(void)y;
	data = (t_data *)param;
	if (!data || !data->mlx.mlxcon || !data->mlx.window)
		return (E);
	mlx = (t_mlx_display_prefix *)data->mlx.mlxcon;
	window = (t_mlx_window_prefix *)data->mlx.window;
	XSetInputFocus(mlx->display, window->window, RevertToParent, CurrentTime);
	XFlush(mlx->display);
	return (S);
}

static int	key_hook(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == XK_Escape)
		return (close_window(data));
	if (apply_transform_key(data, keycode))
		return (render_image(data));
	return (S);
}

static int	render_image(t_data *data)
{
	unsigned int	color;
	unsigned char	*pixel;
	t_camera_frame	frame;
	t_ray			ray;
	t_hit			hit;
	t_rgb			shaded;
	int				bytes_per_pixel;
	int				x;
	int				y;
	int				i;
	int				red;
	int				green;
	int				blue;

	if (!data || !data->mlx.mlxcon || !data->mlx.window
		|| !data->mlx.image || !data->mlx.addr)
		return (printf("Error: renderer is missing an initialized MLX resource.\n"),
			E);
	if ((data->mlx.bits_per_pixel != 24 && data->mlx.bits_per_pixel != 32)
		|| data->mlx.line_length <= 0
		|| (data->mlx.endian != 0 && data->mlx.endian != 1))
		return (printf("Error: unsupported MiniLibX image format.\n"),
			E);
	bytes_per_pixel = data->mlx.bits_per_pixel / 8;
	if (data->mlx.line_length < WIDTH * bytes_per_pixel)
		return (printf("Error: MiniLibX image row is too short.\n"),
			E);
	if (initialize_camera_frame(&data->scene.camera, &frame))
		return (printf("Error: invalid camera orientation or field of view.\n"),
			E);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (camera_ray_for_pixel(&frame, x, y, &ray))
				return (printf("Error: failed to generate camera ray.\n"), E);
			if (intersect_scene(&data->scene, &ray, &hit))
			{
				shaded = shade_hit(&data->scene, &hit);
				red = shaded.r;
				green = shaded.g;
				blue = shaded.b;
			}
			else
			/*{
				red = (int)((ray.direction.x + 1.0) * 127.5);
				green = (int)((ray.direction.y + 1.0) * 127.5);
				blue = (int)((ray.direction.z + 1.0) * 127.5);
			}*/
			{
				red = 10;
				green = 10;
				blue = 10;
			}
			color = (unsigned int)mlx_get_color_value(data->mlx.mlxcon,
					(red << 16) | (green << 8) | blue);
			pixel = (unsigned char *)data->mlx.addr
				+ y * data->mlx.line_length + x * bytes_per_pixel;
			i = 0;
			while (i < bytes_per_pixel)
			{
				if (data->mlx.endian == 0)
					pixel[i] = (unsigned char)((color >> (8 * i)) & 0xFF);
				else
					pixel[i] = (unsigned char)((color
							>> (8 * (bytes_per_pixel - 1 - i))) & 0xFF);
				i++;
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.mlxcon, data->mlx.window,
		data->mlx.image, 0, 0);
	return (S);
}

int	render_scene(t_data *data)
{
	if (render_image(data))
		return (E);
	mlx_hook(data->mlx.window, KeyPress, KeyPressMask, key_hook, data);
	mlx_hook(data->mlx.window, ButtonPress, ButtonPressMask,
		focus_window, data);
	mlx_expose_hook(data->mlx.window, expose_window, data);
	mlx_hook(data->mlx.window, DestroyNotify, StructureNotifyMask,
		close_window, data);
	mlx_loop(data->mlx.mlxcon);
	return (S);
}
