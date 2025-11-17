/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:46:07 by jbdmc             #+#    #+#             */
/*   Updated: 2025/11/17 07:16:45 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** philo_eat	--> depends on philo_pickup_fork (philosopher X picks up 2 forks from the table (mutex lock on both forks on pick up and mutex unlock on lay down))
** philo_sleep	--> depends	on time_to_sleep (philosopher X sleeps for Y ms)
** philo_think	--> doesn't actually depend on anything, it's the time a philosopher needs to take action
** philo_die	--> depends on time_to_die (philosopher X didn't eat for Y ms. If Y ms > time_to_die, philosopher X dies)
*/

void	philo_eat(t_philo *ph)
{
	if ((ph->id % 2) == 0)
	{
		pthread_mutex_lock(ph->left_fork);
		safe_print(ph, "has taken a fork");
		pthread_mutex_lock(ph->right_fork);
		safe_print(ph, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(ph->right_fork);
		safe_print(ph, "has taken a fork");
		pthread_mutex_lock(ph->left_fork);
		safe_print(ph, "has taken a fork");
	}
	ph->last_meal_time = get_time_ms();
	ph->meals_eaten++;
	safe_print(ph, "is eating");
	usleep(ph->data->time_eat * 1000);
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
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
	t_philo	*ph = (t_philo *)arg;
	if (ph->id % 2)
    	usleep(50);
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
