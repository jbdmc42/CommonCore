/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:13:12 by jbdmc             #+#    #+#             */
/*   Updated: 2025/12/02 10:41:01 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// Libraries

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

// Structs

typedef struct s_data					// global struct that contains the general informations needed for the program to work
{
	int				num_philo;			// total number of philosophers
	long long		time_die;			// maximum time a philosopher can live without eating
	long long		time_eat;			// time that a philosopher needs to eat
	long long		time_sleep;			// time that a philosopher needs to sleep
	int				must_eat;			// number of times that each philosopher should eat (if determined)
	long long		start_time;			// initial timestamp for the simulation
	int				simulation_end;		// flag to end the threads safely
	pthread_mutex_t	*forks;				// fork array (contains all forks available to be used by the philosophers)
	pthread_mutex_t	print_mutex;		// mutex to protect the log printing
	pthread_mutex_t	end_mutex;			// mutex to protect the simulation end
	struct s_philo	*philos;			// philosopher array
}	t_data;

typedef struct s_philo					// struct that contains all philosophers (we must create a t_philo * variable to store the philosophers)
{
	int				id;					// number of the philosopher
	int				meals_eaten;		// total meals eaten by the philosopher
	long long		last_meal_time;		// time of the last meal eaten by the philosopher
	pthread_t		thread;				// thread of each philosopher
	pthread_mutex_t	*left_fork;			// pointer for the fork to the left of the philosopher
	pthread_mutex_t	*right_fork;		// pointer for the fork to the right of the philosopher
	pthread_mutex_t	meal_mutex;			// protects last_meal_time & meals_eaten
	t_data			*data;				// access to the global struct (aka the data struct with the general information)
}	t_philo;

// Functions

// main.c:
void	safe_print(t_philo *ph, const char *msg);

// init.c:
long long	get_time_ms(void);
int			init_data(t_data *data, int argc, char **argv);
int 		init_philo(t_data *data);

// philo_actions.c:
void		philo_eat(t_philo *ph);
void		philo_sleep(t_philo *ph);
void		philo_think(t_philo *ph);
void		*philo_routine(void *arg);

// threads.c:
int			create_threads(t_data *data);
void		join_threads(t_data *data);
void		monitor(t_data *data);

// utilities.c:
int			ft_atoi(const char *str);
void		set_simulation_end(t_data *data);
int			is_simulation_end(t_data *data);

#endif

