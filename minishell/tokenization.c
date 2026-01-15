/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:55:49 by jbdmc             #+#    #+#             */
/*   Updated: 2025/12/13 09:58:21 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token(char *value, t_tokentype type, t_token **tokens)
{
	t_token	*new_token;
	t_token	*tmp_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return ;
	new_token->value = ft_strdup(value);
	new_token->type = type;
	new_token->next = NULL;
	if (*tokens == NULL)
	{
		*tokens = new_token;
		return ;
	}
	tmp_token = *tokens;
	while (tmp_token->next)
		tmp_token = tmp_token->next;
	tmp_token->next = new_token;
}





// temp
void	print_tokens(t_token *tokens)
{	
	while (tokens)
	{
		printf("TOKEN: %-12s | TYPE: %d\n", tokens->value, tokens->type);
		tokens = tokens->next;
	}
}