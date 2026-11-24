#include "../../include/minirt.h"

static int	initialize_mlx(t_data *data)
{
	data->mlx.mlxcon = mlx_init();
	if (!data->mlx.mlxcon)
		return (E);
	return (S);
}

static int	initialize_window(t_data *data)
{
	data->mlx.window = mlx_new_window(
			data->mlx.mlxcon,
			WIDTH,
			HEIGHT,
			"MiniRT"
			);
	if (!data->mlx.window)
		return (E);
	return (S);
}

static int	initialize_image(t_data *data)
{
	data->mlx.image = mlx_new_image(
			data->mlx.mlxcon,
			WIDTH,
			HEIGHT
			);
	if (!data->mlx.image)
		return (E);
	data->mlx.addr = mlx_get_data_addr(
			data->mlx.image,
			&data->mlx.bits_per_pixel,
			&data->mlx.line_length,
			&data->mlx.endian
			);
	if (!data->mlx.addr)
		return (E);
	return (S);
}

static int	initialize_data(t_data *data)
{
	if (!data)
		return (E);
	ft_memset(data, 0, sizeof(t_data));
	return (S);
}

int	initialize_program(t_data *data)
{
	if (initialize_data(data))
		return (printf("Error: couldn't initialize data"), E);
	if (initialize_mlx(data))
		return (printf("Error: couldn't initialize MLX"), E);
	if (initialize_window(data))
		return (printf("Error: couldn't initialize program's window"), E);
	if (initialize_image(data))
		return (printf("Error: couldn't initialize image"), E);
	return (S);
}
