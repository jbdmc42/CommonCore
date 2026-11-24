#include "minirt.h"

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
	t_data					*data;
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
