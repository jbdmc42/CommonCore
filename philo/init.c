/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 05:11:54 by jbdmc             #+#    #+#             */
/*   Updated: 2026/01/15 09:22:30 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

static int	check_init(t_data *data, int argc)
{
	if (data->num_philo <= 0 || data->time_die <= 0 || data->time_eat <= 0
		|| data->time_sleep <= 0 || (argc == 6 && data->must_eat < 0))
	{
		write(2, "Invalid arguments.\n", 19);
		return (1);
	}
	if (argc == 6 && data->must_eat == 0)
		exit(0);
	printf(" TIMESTAMP (ms) | ACTION\n");
	return (0);
}

static void	init_generals(t_data *data)
{
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->end_mutex, NULL);
	pthread_mutex_init(&data->waiter_mutex, NULL);
	pthread_cond_init(&data->waiter_cond, NULL);
	data->simulation_end = 0;
	data->start_time = get_time_ms();
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->num_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	if (check_init(data, argc) == 1)
		return (1);
	if (init_forks_malloc(data) == 1)
		return (1);
	if (init_forks_mutex(data) == 1)
		return (1);
	init_generals(data);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philos)
		return (write(2, "Malloc error\n", 13), 1);
	i = 0;
	while (i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = data->start_time;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philo];
		data->philos[i].left_index = i;
		data->philos[i].right_index = (i + 1) % data->num_philo;
		data->philos[i].waiting = 0;
		pthread_mutex_init(&data->philos[i].meal_mutex, NULL);
		i++;
	}
	return (0);
}
