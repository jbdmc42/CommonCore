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

static long long	get_last_meal_time(t_philo *ph)
{
	long long	last_meal;

	pthread_mutex_lock(&ph->meal_mutex);
	last_meal = ph->last_meal_time;
	pthread_mutex_unlock(&ph->meal_mutex);
	return (last_meal);
}

static t_philo	*choose_hungriest_waiting(t_data *data)
{
	int			i;
	long long	now;
	long long	best_hunger;
	t_philo		*best;

	now = get_time_ms();
	best = NULL;
	best_hunger = -1;
	i = 0;
	while (i < data->num_philo)
	{
		t_philo *p = &data->philos[i];
		if (p->waiting)
		{
			long long hunger = now - get_last_meal_time(p);
			if (!best || hunger > best_hunger
				|| (hunger == best_hunger && p->id < best->id))
			{
				best = p;
				best_hunger = hunger;
			}
		}
		i++;
	}
	return (best);
}

static int	forks_overlap(t_philo *a, t_philo *b)
{
	if (!a || !b)
		return (0);
	if (a->left_index == b->left_index || a->left_index == b->right_index)
		return (1);
	if (a->right_index == b->left_index || a->right_index == b->right_index)
		return (1);
	return (0);
}

static int	reserve_forks_fair(t_philo *ph)
{
	t_data	*data;

	data = ph->data;
	pthread_mutex_lock(&data->waiter_mutex);
	ph->waiting = 1;
	while (!is_simulation_end(data))
	{
		t_philo *priority = choose_hungriest_waiting(data);
		if (priority && priority != ph && forks_overlap(ph, priority))
		{
			pthread_cond_wait(&data->waiter_cond, &data->waiter_mutex);
			continue ;
		}
		if (data->fork_in_use[ph->left_index] == 0
			&& data->fork_in_use[ph->right_index] == 0
			&& (!priority || priority == ph || !forks_overlap(ph, priority)))
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

static void	release_reserved_forks(t_philo *ph)
{
	t_data	*data;

	data = ph->data;
	pthread_mutex_lock(&data->waiter_mutex);
	data->fork_in_use[ph->left_index] = 0;
	data->fork_in_use[ph->right_index] = 0;
	pthread_cond_broadcast(&data->waiter_cond);
	pthread_mutex_unlock(&data->waiter_mutex);
}

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
	if (!reserve_forks_fair(ph))
		return ;
	if (is_simulation_end(ph->data))
	{
		release_reserved_forks(ph);
		return ;
	}
	pthread_mutex_lock(first);
	safe_print(ph, "has taken a fork");
	if (is_simulation_end(ph->data))
	{
		pthread_mutex_unlock(first);
		release_reserved_forks(ph);
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
