/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:53:14 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_shell *shell)
{
	char	cwd[PATH_MAX];
	char	*logical_pwd;

	if (getcwd(cwd, PATH_MAX) != NULL)
	{
		printf("%s\n", cwd);
		return ;
	}
	logical_pwd = env_get_value(shell->env, "PWD");
	if (logical_pwd)
	{
		printf("%s\n", logical_pwd);
		free(logical_pwd);
	}
}
