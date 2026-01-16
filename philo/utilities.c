/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:40:14 by jbdmc             #+#    #+#             */
/*   Updated: 2026/01/15 09:22:29 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	val;

	i = 0;
	res = 0;
	val = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			val *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = str[i] - '0' + res * 10;
		i++;
	}
	return (res * val);
}

void	set_simulation_end(t_data *data)
{
	pthread_mutex_lock(&data->end_mutex);
	data->simulation_end = 1;
	pthread_mutex_unlock(&data->end_mutex);
	pthread_mutex_lock(&data->waiter_mutex);
	pthread_cond_broadcast(&data->waiter_cond);
	pthread_mutex_unlock(&data->waiter_mutex);
}

int	is_simulation_end(t_data *data)
{
	int	val;

	pthread_mutex_lock(&data->end_mutex);
	val = data->simulation_end;
	pthread_mutex_unlock(&data->end_mutex);
	return (val);
}

int	init_forks_malloc(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (write(2, "Malloc error\n", 13), 1);
	data->fork_in_use = malloc(sizeof(int) * data->num_philo);
	if (!data->fork_in_use)
	{
		free(data->forks);
		data->forks = NULL;
		return (write(2, "Malloc error\n", 13), 1);
	}
	return (0);
}

int	init_forks_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		data->fork_in_use[i] = 0;
		i++;
	}
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (write(2, "Mutex init error\n", 17), 1);
		i++;
	}
	return (0);
}
