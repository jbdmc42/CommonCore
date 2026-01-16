/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:36:00 by jbdmc             #+#    #+#             */
/*   Updated: 2026/01/15 09:36:00 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	wait_for_priority(t_philo *ph, t_data *data, t_philo *priority)
{
	if (priority && priority != ph && forks_overlap(ph, priority))
	{
		pthread_cond_wait(&data->waiter_cond, &data->waiter_mutex);
		return (1);
	}
	return (0);
}

static int	can_reserve_forks(t_philo *ph, t_data *data, t_philo *priority)
{
	if (data->fork_in_use[ph->left_index] == 0
		&& data->fork_in_use[ph->right_index] == 0
		&& (!priority || priority == ph || !forks_overlap(ph, priority)))
		return (1);
	return (0);
}

int	reserve_forks_fair(t_philo *ph)
{
	t_data	*data;
	t_philo	*priority;

	data = ph->data;
	pthread_mutex_lock(&data->waiter_mutex);
	ph->waiting = 1;
	while (!is_simulation_end(data))
	{
		priority = choose_hungriest_waiting(data);
		if (wait_for_priority(ph, data, priority))
			continue ;
		if (can_reserve_forks(ph, data, priority))
		{
			data->fork_in_use[ph->left_index] = 1;
			data->fork_in_use[ph->right_index] = 1;
			ph->waiting = 0;
			pthread_mutex_unlock(&data->waiter_mutex);
			return (1);
		}
		pthread_cond_wait(&data->waiter_cond, &data->waiter_mutex);
	}
	ph->waiting = 0;
	pthread_mutex_unlock(&data->waiter_mutex);
	return (0);
}
