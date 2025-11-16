/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:13:12 by jbdmc             #+#    #+#             */
/*   Updated: 2025/11/12 09:56:37 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// Libraries

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>	// remove if memset is not needed

// Structs

typedef struct s_philo
{
	int		id;
	int		e
}	t_philo;

typedef struct s_data
{
	int		num_philo;
	int		time;
	int		time_eat;
	int		time_die;
	int		time_sleep;
}	t_data;

// Functions

// utilities.c:
int		ft_atoi(const char *str);

#endif

