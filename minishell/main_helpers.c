/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:10:00 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_input_line(char **line, t_shell *shell)
{
	size_t	start;

	if (!*line)
	{
		if (g_signal_received)
			return (g_signal_received = 0, shell->exit_status = 130, 0);
		clean_exit(shell);
	}
	if (g_signal_received)
	{
		shell->exit_status = 130;
		g_signal_received = 0;
		free(*line);
		*line = NULL;
		return (0);
	}
	start = skip_blank_prefix(*line);
	if ((*line)[start] == '\0')
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	return (1);
}

void	execute_line(char *line, t_shell *shell, int interactive)
{
	t_token	*tokens;
	char	*validated_line;

	validated_line = read_input_with_continuation(line, shell);
	if (interactive && validated_line)
		add_history(line);
	if (!validated_line)
		return ;
	tokens = NULL;
	parse_input(validated_line, 0, &tokens, shell);
}

int	run_interactive_cycle(t_shell *shell)
{
	char	*line;

	line = readline(PROMPT);
	if (!process_input_line(&line, shell))
		return (0);
	execute_line(line, shell, 1);
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (1);
}

int	run_noninteractive_cycle(t_shell *shell)
{
	char		*line;
	char		*buf;
	ssize_t		nread;
	size_t		len;

	len = 0;
	buf = NULL;
	nread = ft_getline_fd(&buf, &len, STDIN_FILENO);
	if (nread == -1)
	{
		free(buf);
		clean_exit(shell);
	}
	if (nread > 0 && buf[nread - 1] == '\n')
		buf[nread - 1] = '\0';
	line = buf;
	if (!process_input_line(&line, shell))
		return (0);
	execute_line(line, shell, 0);
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (1);
}
