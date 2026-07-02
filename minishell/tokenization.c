/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:55:49 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
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
	if (!new_token->value)
	{
		free(new_token);
		return ;
	}
	new_token->type = type;
	new_token->next = NULL;
	new_token->heredoc_fd = -1;
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

void	print_tokens(t_token *tokens)
{
	while (tokens)
	{
		printf("TOKEN: %-12s | TYPE: %d\n", tokens->value, tokens->type);
		tokens = tokens->next;
	}
}

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens->next;
		if (tokens->heredoc_fd >= 0)
			close(tokens->heredoc_fd);
		free(tokens->value);
		free(tokens);
		tokens = tmp;
	}
}
