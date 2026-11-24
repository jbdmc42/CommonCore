#include "minirt.h"

static int	validate_image(t_data *data, int *bytes_per_pixel)
{
	if (!data || !data->mlx.mlxcon || !data->mlx.window
		|| !data->mlx.image || !data->mlx.addr)
		return (printf("Error: renderer is missing an "
				"initialized MLX resource.\n"), E);
	if ((data->mlx.bits_per_pixel != 24
			&& data->mlx.bits_per_pixel != 32)
		|| data->mlx.line_length <= 0
		|| (data->mlx.endian != 0 && data->mlx.endian != 1))
		return (printf("Error: unsupported MiniLibX image format.\n"), E);
	*bytes_per_pixel = data->mlx.bits_per_pixel / 8;
	if (data->mlx.line_length < WIDTH * *bytes_per_pixel)
		return (printf("Error: MiniLibX image row is too short.\n"), E);
	return (S);
}

static int	get_pixel_color(t_data *data, t_camera_frame *frame,
		t_vector *pixel_pos, t_rgb *rgb)
{
	t_ray	ray;
	t_hit	hit;
	t_rgb	shaded;

	if (camera_ray_for_pixel(frame, (int)pixel_pos->x,
			(int)pixel_pos->y, &ray))
		return (E);
	if (intersect_scene(&data->scene, &ray, &hit))
	{
		shaded = shade_hit(&data->scene, &hit);
		rgb->r = shaded.r;
		rgb->g = shaded.g;
		rgb->b = shaded.b;
	}
	else
	{
		rgb->r = 10;
		rgb->g = 10;
		rgb->b = 10;
	}
	return (S);
}

static int	render_pixel(t_data *data, t_camera_frame *frame,
		int x, int y)
{
	t_rgb			rgb;
	unsigned int	color;
	unsigned char	*pixel;
	int				bytes_per_pixel;
	int				i;

	bytes_per_pixel = data->mlx.bits_per_pixel / 8;
	if (get_pixel_color(data, frame,
			&(t_vector){(double)x, (double)y, 0}, &rgb))
		return (E);
	color = mlx_get_color_value(data->mlx.mlxcon,
			(rgb.r << 16) | (rgb.g << 8) | rgb.b);
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
	return (S);
}

int	render_image(t_data *data)
{
	t_camera_frame	frame;
	int				bytes_per_pixel;
	int				x;
	int				y;

	if (validate_image(data, &bytes_per_pixel))
		return (E);
	if (initialize_camera_frame(&data->scene.camera, &frame))
		return (printf("Error: invalid camera orientation "
				"or field of view.\n"), E);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (render_pixel(data, &frame, x, y))
				return (printf("Error: failed to render pixel.\n"), E);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.mlxcon, data->mlx.window,
		data->mlx.image, 0, 0);
	return (S);
}
