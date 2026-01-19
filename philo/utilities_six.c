/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:38:00 by jbdmc             #+#    #+#             */
/*   Updated: 2026/01/15 09:38:00 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_death(t_data *data, int i)
{
	long long	last_meal;

	pthread_mutex_lock(&data->philos[i].meal_mutex);
	last_meal = data->philos[i].last_meal_time;
	pthread_mutex_unlock(&data->philos[i].meal_mutex);
	if ((get_time_ms() - last_meal) > data->time_die)
	{
		safe_print(&data->philos[i], "died");
		set_simulation_end(data);
		return (1);
	}
	return (0);
}

int	check_all_ate(t_data *data, int i)
{
	int	meals;

	pthread_mutex_lock(&data->philos[i].meal_mutex);
	meals = data->philos[i].meals_eaten;
	pthread_mutex_unlock(&data->philos[i].meal_mutex);
	if (data->must_eat != -1 && meals < data->must_eat)
		return (0);
	return (1);
}
