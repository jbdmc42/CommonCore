/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:46:07 by jbdmc             #+#    #+#             */
/*   Updated: 2025/12/02 10:40:47 by jbdmc            ###   ########.fr       */
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
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	// Determine a total order: always lock the lower-addressed fork first
	if (ph->left_fork < ph->right_fork)
	{
		first = ph->left_fork;
		second = ph->right_fork;
	}
	else
	{
		first = ph->right_fork;
		second = ph->left_fork;
	}

	// Single philosopher: can only take one fork and will starve until monitor ends
	if (ph->data->num_philo == 1)
	{
		pthread_mutex_lock(first);
		safe_print(ph, "has taken a fork");
		// Wait until simulation ends (monitor will set it)
		while (!is_simulation_end(ph->data))
			usleep(1000);
		pthread_mutex_unlock(first);
		return ;
	}
	pthread_mutex_lock(first);
	safe_print(ph, "has taken a fork");
	if (is_simulation_end(ph->data))
	{
		pthread_mutex_unlock(first);
		return ;
	}
	pthread_mutex_lock(second);
	safe_print(ph, "has taken a fork");

	// Update meal info under protection
	pthread_mutex_lock(&ph->meal_mutex);
	ph->last_meal_time = get_time_ms();
	ph->meals_eaten++;
	pthread_mutex_unlock(&ph->meal_mutex);

	safe_print(ph, "is eating");
	usleep(ph->data->time_eat * 1000);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(second);
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
