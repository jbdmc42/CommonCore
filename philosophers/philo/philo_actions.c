/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:46:07 by jbdmc             #+#    #+#             */
/*   Updated: 2026/01/15 09:25:56 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	lock_forks(t_philo *ph, pthread_mutex_t *first,
		pthread_mutex_t *second)
{
	pthread_mutex_lock(first);
	safe_print(ph, "has taken a fork");
	if (is_simulation_end(ph->data))
	{
		pthread_mutex_unlock(first);
		release_reserved_forks(ph);
		return (0);
	}
	pthread_mutex_lock(second);
	safe_print(ph, "has taken a fork");
	return (1);
}

void	philo_eat(t_philo *ph)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	get_fork_order(ph, &first, &second);
	if (ph->data->num_philo == 1)
	{
		handle_single_philo(ph, first);
		return ;
	}
	if (!reserve_forks_fair(ph))
		return ;
	if (is_simulation_end(ph->data))
	{
		release_reserved_forks(ph);
		return ;
	}
	if (!lock_forks(ph, first, second))
		return ;
	update_meal_info(ph);
	safe_print(ph, "is eating");
	usleep(ph->data->time_eat * 1000);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(second);
	release_reserved_forks(ph);
}

void	philo_sleep(t_philo *ph)
{
	safe_print(ph, "is sleeping");
	usleep(ph->data->time_sleep * 1000);
}

void	philo_think(t_philo *ph)
{
	safe_print(ph, "is thinking");
	usleep(50);
}

void	*philo_routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (ph->id % 2)
	{
		safe_print(ph, "is thinking");
		usleep(50);
	}
	while (!is_simulation_end(ph->data))
	{
		philo_eat(ph);
		if (is_simulation_end(ph->data))
			break ;
		philo_sleep(ph);
		if (is_simulation_end(ph->data))
			break ;
		philo_think(ph);
	}
	return (NULL);
}
