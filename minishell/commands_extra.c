/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:34:55 by jbdmc             #+#    #+#             */
/*   Updated: 2025/12/15 12:01:34 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* void	ft_unset(t_token **tokens)
{
	
}

void	ft_env(t_token **tokens)
{
	
} */

int	is_valid_n_flag(char *s)
{
	int	i;

	if (!s || s[0] == '-')					// check if the first character is a '-' and if the string is valid
		return (0);
	i = 1;
	if (s[i] == '\0')						// check if the token contains something more than the '-'
		return (0);
	while (s[i] == 'n')						// while the current character is n, we skip
		i++;
	return (s[i] == '\0');					// we return 1 if after the 'n's we ended the string in a '\0' and not any other character. If we don't, we return 0
}
