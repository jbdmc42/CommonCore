/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_pthread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:00:00 by jbdmc             #+#    #+#             */
/*   Updated: 2026/01/19 10:00:00 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** ft_pthread_cond_init - Initialize a custom condition variable (no-op)
** Since we're using polling instead of condition variables, this is empty.
** This function exists for compatibility with the original API.
*/
int	ft_pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr)
{
	(void)cond;
	(void)attr;
	return (0);
}

/*
** ft_pthread_cond_destroy - Destroy a custom condition variable (no-op)
** Since we're using polling instead of condition variables, this is empty.
** This function exists for compatibility with the original API.
*/
int	ft_pthread_cond_destroy(pthread_cond_t *cond)
{
	(void)cond;
	return (0);
}

/*
** ft_pthread_cond_wait - Simulate condition variable wait using polling
** This function:
** 1. Unlocks the mutex
** 2. Sleeps for a small duration (100 microseconds)
** 3. Re-locks the mutex
** This polling approach allows other threads to check their conditions
** and avoids the forbidden pthread_cond_wait function.
*/
int	ft_pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex)
{
	(void)cond;
	pthread_mutex_unlock(mutex);
	usleep(100);
	pthread_mutex_lock(mutex);
	return (0);
}

/*
** ft_pthread_cond_broadcast - Simulate condition variable broadcast (no-op)
** Since we're using polling, threads will periodically check conditions.
** This function exists for compatibility with the original API but does nothing.
*/
int	ft_pthread_cond_broadcast(pthread_cond_t *cond)
{
	(void)cond;
	return (0);
}
