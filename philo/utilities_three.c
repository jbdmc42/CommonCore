/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:35:00 by jbdmc             #+#    #+#             */
/*   Updated: 2026/01/15 09:35:00 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	forks_overlap(t_philo *a, t_philo *b)
{
	if (!a || !b)
		return (0);
	if (a->left_index == b->left_index || a->left_index == b->right_index)
		return (1);
	if (a->right_index == b->left_index || a->right_index == b->right_index)
		return (1);
	return (0);
}

void	release_reserved_forks(t_philo *ph)
{
	t_data	*data;

	data = ph->data;
	pthread_mutex_lock(&data->waiter_mutex);
	data->fork_in_use[ph->left_index] = 0;
	data->fork_in_use[ph->right_index] = 0;
	pthread_cond_broadcast(&data->waiter_cond);
	pthread_mutex_unlock(&data->waiter_mutex);
}

t_philo	*choose_hungriest_waiting(t_data *data)
{
	int			i;
	long long	now;
	long long	best_hunger;
	long long	hunger;
	t_philo		*best;

	now = get_time_ms();
	best = NULL;
	best_hunger = -1;
	i = -1;
	while (++i < data->num_philo)
	{
		if (data->philos[i].waiting)
		{
			hunger = now - get_last_meal_time(&data->philos[i]);
			if (is_better_candidate(best, best_hunger, hunger,
					data->philos[i].id))
			{
				best = &data->philos[i];
				best_hunger = hunger;
			}
		}
	}
	return (best);
}
