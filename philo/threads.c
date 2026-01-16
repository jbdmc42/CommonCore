/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 06:21:03 by jbdmc             #+#    #+#             */
/*   Updated: 2026/01/15 09:17:23 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, philo_routine,
				&data->philos[i]) != 0)
			return (write(2, "Error creating thread\n", 22), 1);
		i++;
	}
	return (0);
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

void	monitor(t_data *data)
{
	int	i;
	int	all_ate;

	while (!is_simulation_end(data))
	{
		i = 0;
		all_ate = 1;
		while (i < data->num_philo)
		{
			if (check_philo_death(data, i))
				return ;
			if (!check_all_ate(data, i))
				all_ate = 0;
			i++;
		}
		if (data->must_eat != -1 && all_ate)
		{
			set_simulation_end(data);
			return ;
		}
		usleep(1000);
	}
}
