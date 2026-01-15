/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:44:36 by jbdmc             #+#    #+#             */
/*   Updated: 2025/12/15 15:30:29 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// use this function to free all allocations
void	free_all(void)
{
	// free everything needed before closing/reseting here
}

// use this function to exit minishell freeing all before closing
void	clean_exit(void)
{
	free_all();
	printf(EXIT);
	g_global.exit_status = 2;
	exit(g_global.exit_status);
}