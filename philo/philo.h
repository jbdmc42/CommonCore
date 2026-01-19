/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:13:12 by jbdmc             #+#    #+#             */
/*   Updated: 2026/01/15 09:22:29 by jbdmc            ###   ########.fr       */
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

typedef struct s_data
{
	int				num_philo;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	int				must_eat;
	long long		start_time;
	int				simulation_end;
	pthread_mutex_t	*forks;
	int				*fork_in_use;
	pthread_mutex_t	waiter_mutex;
	pthread_cond_t	waiter_cond;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	end_mutex;
	struct s_philo	*philos;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				left_index;
	int				right_index;
	int				waiting;
	pthread_mutex_t	meal_mutex;
	t_data			*data;
}	t_philo;

void		safe_print(t_philo *ph, const char *msg);

long long	get_time_ms(void);
int			init_data(t_data *data, int argc, char **argv);
int			init_philo(t_data *data);

void		philo_eat(t_philo *ph);
void		philo_sleep(t_philo *ph);
void		philo_think(t_philo *ph);
void		*philo_routine(void *arg);

int			create_threads(t_data *data);
void		join_threads(t_data *data);
void		monitor(t_data *data);

int			ft_atoi(const char *str);
void		set_simulation_end(t_data *data);
int			is_simulation_end(t_data *data);
int			init_forks_malloc(t_data *data);
int			init_forks_mutex(t_data *data);

long long	get_last_meal_time(t_philo *ph);
int			is_better_candidate(t_philo *best, long long best_hunger,
				long long hunger, int id);

int			forks_overlap(t_philo *a, t_philo *b);
void		release_reserved_forks(t_philo *ph);
t_philo		*choose_hungriest_waiting(t_data *data);

int			reserve_forks_fair(t_philo *ph);

void		handle_single_philo(t_philo *ph, pthread_mutex_t *fork);
void		update_meal_info(t_philo *ph);
void		get_fork_order(t_philo *ph, pthread_mutex_t **first,
				pthread_mutex_t **second);

int			check_philo_death(t_data *data, int i);
int			check_all_ate(t_data *data, int i);

int			ft_pthread_cond_init(pthread_cond_t *cond,
				const pthread_condattr_t *attr);
int			ft_pthread_cond_destroy(pthread_cond_t *cond);
int			ft_pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
int			ft_pthread_cond_broadcast(pthread_cond_t *cond);

#endif