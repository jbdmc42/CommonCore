/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:18:09 by jbdmc             #+#    #+#             */
/*   Updated: 2025/12/15 15:29:55 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_token **tokens)
{
	int		flag;
	int		first;
	t_token	*cur;

	flag = 1;
	first = 1;
	cur = (*tokens)->next;
	while (cur && cur->type == WORD && is_valid_n_flag(cur->value))			// process -n flags
	{
		flag = 0;
		cur = cur->next;
	}
	while (cur)																// print all arguments following the flags or command
	{
		if (!first)
			write(1, " ", 1);
		write(1, cur->value, ft_strlen(cur->value));
		first = 0;
		cur = cur->next;
	}
	if (flag)
		write(1, "\n", 1);
	return ;
}

/* void	ft_cd(t_token **tokens)
{
	
}

void	ft_pwd(t_token **tokens)
{
	
}

void	ft_export(t_token **tokens)
{
	
} */

void	get_commands(t_token **tokens)
{
	if (!tokens || !*tokens || !(*tokens)->value)
		return ;	
	if (ft_strncmp((*tokens)->value, "echo", 4) == 0)
        ft_echo(tokens);
   /*  else if (ft_strncmp((*tokens)->value, "cd", 3) == 0)
        ft_cd(tokens);
    else if (ft_strncmp((*tokens)->value, "pwd", 4) == 0)
        ft_pwd(tokens);
    else if (ft_strncmp((*tokens)->value, "export", 7) == 0)
        ft_export(tokens);
    else if (ft_strncmp((*tokens)->value, "unset", 6) == 0)
        ft_unset(tokens);
    else if (ft_strncmp((*tokens)->value, "env", 4) == 0)
        ft_env(tokens); */
    else if (ft_strncmp((*tokens)->value, "exit", 4) == 0)
        clean_exit();
    else
    {
        printf("%s: command not found\n", (*tokens)->value);
        g_global.exit_status = 127;
    }
}
