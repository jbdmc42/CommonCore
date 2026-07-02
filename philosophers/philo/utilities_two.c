/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:30:00 by jbdmc             #+#    #+#             */
/*   Updated: 2026/01/15 09:30:00 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_last_meal_time(t_philo *ph)
{
	long long	last_meal;

	pthread_mutex_lock(&ph->meal_mutex);
	last_meal = ph->last_meal_time;
	pthread_mutex_unlock(&ph->meal_mutex);
	return (last_meal);
}

int	is_better_candidate(t_philo *best, long long best_hunger,
		long long hunger, int id)
{
	if (!best)
		return (1);
	if (hunger > best_hunger)
		return (1);
	if (hunger == best_hunger && id < best->id)
		return (1);
	return (0);
}
