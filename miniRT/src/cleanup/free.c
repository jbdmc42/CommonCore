#include "minirt.h"

void	free_objects(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->scene.obj_count)
	{
		free(data->scene.objs[i].obj);
		i++;
	}
	free(data->scene.objs);
}