/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:25:30 by jbdmc             #+#    #+#             */
/*   Updated: 2026/01/15 09:22:30 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	safe_print(t_philo *ph, const char *msg)
{
	long long	timestamp;

	pthread_mutex_lock(&ph->data->print_mutex);
	if (!is_simulation_end(ph->data) || (msg && ft_strcmp(msg, "died") == 0))
	{
		timestamp = get_time_ms() - ph->data->start_time;
		printf("%15lld | Philosopher %d %s\n", timestamp, ph->id, msg);
	}
	pthread_mutex_unlock(&ph->data->print_mutex);
}

static void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->philos[i].meal_mutex);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->waiter_mutex);
	pthread_cond_destroy(&data->waiter_cond);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->end_mutex);
	free(data->forks);
	free(data->fork_in_use);
	free(data->philos);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		write(1, "Invalid argument count. Usage: ./philo <number_of_", 50);
		write(1, "philosophers> <time_to_die> <time_to_eat> <time_to_s", 52);
		write(1, "leep> <[number_of_times_each_philosopher_must_eat]>\n", 52);
		return (1);
	}
	if (init_data(&data, argc, argv) != 0)
		return (1);
	if (init_philo(&data) != 0)
		return (1);
	if (create_threads(&data) != 0)
		return (1);
	monitor(&data);
	set_simulation_end(&data);
	join_threads(&data);
	cleanup(&data);
	return (0);
}
