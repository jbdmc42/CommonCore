/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:54:22 by jbdmc             #+#    #+#             */
/*   Updated: 2025/12/08 11:52:47 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_input(char *line, size_t i)
{
	int	flag;

	flag = 0;
	if (found_echo(line, i, &flag))
		ft_echo(line, i, &flag);
	/* else if (found_cd(line, i))
		ft_cd();
	else if (found_pwd(line, i))
		ft_pwd();
	else if (found_export(line, i))
		ft_export();
	else if (found_unset(line, i))
		ft_unset();
	else if (found_env(line, i))
		ft_env(); */
}
