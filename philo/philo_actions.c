/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:46:07 by jbdmc             #+#    #+#             */
/*   Updated: 2025/11/12 09:51:37 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** philo_eat	--> depends on philo_pickup_fork (philosopher X picks up 2 forks from the table (mutex lock on both forks on pick up and mutex unlock on lay down))
** philo_sleep	--> depends	on time_to_sleep (philosopher X sleeps for Y ms)
** philo_think	--> doesn't actually depend on anything, it's the time a philosopher needs to take action
** philo_die	--> depends on time_to_die (philosopher X didn't eat for Y ms. If Y ms > time_to_die, philosopher X dies)
*/