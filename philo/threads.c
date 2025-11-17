/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 06:21:03 by jbdmc             #+#    #+#             */
/*   Updated: 2025/11/17 06:56:38 by jbdmc            ###   ########.fr       */
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
			if ((get_time_ms() - data->philos[i].last_meal_time) > data->time_die)		// check if any philosopher died
			{
				safe_print(&data->philos[i], "died");
				set_simulation_end(data);
				return ; 
			}
			if (data->must_eat != -1 && data->philos[i].meals_eaten < data->must_eat)	// check if all philosophers ate their meals
				all_ate = 0;
			i++;
		}
		if (data->must_eat != -1 && all_ate)
		{
			set_simulation_end(data);
			return ;
		}
		usleep(1000);	// sleep for 1ms
	}
}
