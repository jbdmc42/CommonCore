/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-b <jpaulo-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:38:33 by jpaulo-b          #+#    #+#             */
/*   Updated: 2026/10/27 16:44:10 by jpaulo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	initialize_camera_frame(const t_camera *camera, t_camera_frame *frame)
{
	t_vector	world_up;
	double		forward_length;
	double		fov_radians;

	if (!camera || !frame || camera->fov <= 0 || camera->fov >= 180)
		return (E);
	forward_length = sqrt(camera->orientation.x * camera->orientation.x
			+ camera->orientation.y * camera->orientation.y
			+ camera->orientation.z * camera->orientation.z);
	if (forward_length == 0.0 || !isfinite(forward_length))
		return (E);
	frame->origin = camera->position;
	frame->forward = vector_norm(camera->orientation);
	world_up.x = 0.0;
	world_up.y = 1.0;
	world_up.z = 0.0;
	if (fabs(frame->forward.y) > 0.999)
	{
		world_up.x = 0.0;
		world_up.y = 0.0;
		world_up.z = 1.0;
	}
	frame->right = vector_norm(vector_cross(frame->forward, world_up));
	frame->up = vector_cross(frame->right, frame->forward);
	fov_radians = camera->fov * (M_PI / 180.0);
	frame->half_view_height = tan(fov_radians / 2.0);
	frame->half_view_width = frame->half_view_height
		* ((double)WIDTH / (double)HEIGHT);
	if (!isfinite(frame->half_view_width)
		|| !isfinite(frame->half_view_height))
		return (E);
	return (S);
}

int	camera_ray_for_pixel(const t_camera_frame *frame, int x, int y,
		t_ray *ray)
{
	double	horizontal;
	double	vertical;

	if (!frame || !ray || x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (E);
	horizontal = (2.0 * ((x + 0.5) / WIDTH) - 1.0)
		* frame->half_view_width;
	vertical = (1.0 - 2.0 * ((y + 0.5) / HEIGHT))
		* frame->half_view_height;
	ray->origin = frame->origin;
	ray->direction.x = frame->forward.x + frame->right.x * horizontal
		+ frame->up.x * vertical;
	ray->direction.y = frame->forward.y + frame->right.y * horizontal
		+ frame->up.y * vertical;
	ray->direction.z = frame->forward.z + frame->right.z * horizontal
		+ frame->up.z * vertical;
	ray->direction = vector_norm(ray->direction);
	return (S);
}
