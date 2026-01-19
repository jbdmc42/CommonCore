/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:37:00 by jbdmc             #+#    #+#             */
/*   Updated: 2026/01/15 09:37:00 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_single_philo(t_philo *ph, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	safe_print(ph, "has taken a fork");
	while (!is_simulation_end(ph->data))
		usleep(1000);
	pthread_mutex_unlock(fork);
}

void	update_meal_info(t_philo *ph)
{
	pthread_mutex_lock(&ph->meal_mutex);
	ph->last_meal_time = get_time_ms();
	ph->meals_eaten++;
	pthread_mutex_unlock(&ph->meal_mutex);
}

void	get_fork_order(t_philo *ph, pthread_mutex_t **first,
		pthread_mutex_t **second)
{
	if (ph->left_fork < ph->right_fork)
	{
		*first = ph->left_fork;
		*second = ph->right_fork;
	}
	else
	{
		*first = ph->right_fork;
		*second = ph->left_fork;
	}
}
