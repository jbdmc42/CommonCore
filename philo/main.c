/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:25:30 by jbdmc             #+#    #+#             */
/*   Updated: 2025/11/12 09:46:05 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo(void)
{
	
}

int	main(int argc, char **argv)
{
	int	cycle;
	
	if (argc < 5 || argc > 6)
	{
		write(1, "Invalid argument count. Usage: ./philo <number_of_", 50);
		write(1, "philosophers> <time_to_die> <time_to_eat> <time_to_s", 52);
		write(1, "leep> <[number_of_times_each_philosopher_must_eat]>\n", 52);
	cycle = 0;
	if (argc == 6)
	{
		cycle = ft_atoi(argv[6]);
		while (cycle > 0)
		{
			ft_philo();
			cycle--;
		}
		return (0);
	}
	while (1)
		ft_philo();
	return (0);
}