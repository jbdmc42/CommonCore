/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-b <jpaulo-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:17:39 by jpaulo-b          #+#    #+#             */
/*   Updated: 2026/10/27 17:38:35 by jpaulo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//  dot product of two vectors (prod. interno (Port.))
double	vector_dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

//  cross product of two vectors (prod. externo (Port.))
t_vector	vector_cross(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}

//  length of a vector
double	vector_len(t_vector v)
{
	double	len_x;
	double	len_y;
	double	len_z;
	double	sum;

	len_x = v.x * v.x;
	len_y = v.y * v.y;
	len_z = v.z * v.z;
	sum = len_x + len_y + len_z;
	return (sqrt(sum));
}

//  normalizing a vector - its coordinates when its length is 1
t_vector	vector_norm(t_vector v)
{
	t_vector	res;
	double		len;

	len = vector_len(v);
	if (len == 0)
		return (v);
	res.x = v.x / len;
	res.y = v.y / len;
	res.z = v.z / len;
	return (res);
}

// function to increase or decrease the scale of a vector
t_vector	vector_scale(t_vector vector, double scale)
{
	vector.x *= scale;
	vector.y *= scale;
	vector.z *= scale;
	return (vector);
}
