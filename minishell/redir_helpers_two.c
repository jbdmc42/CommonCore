/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_helpers_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 19:00:00 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>
#include <unistd.h>

static char	*append_char_to_line(char *line, size_t len, char c)
{
	char	*new;

	new = malloc(len + 2);
	if (!new)
	{
		free(line);
		return (NULL);
	}
	if (line)
	{
		ft_memcpy(new, line, len);
		free(line);
	}
	new[len] = c;
	new[len + 1] = '\0';
	return (new);
}

static char	*read_line_from_fd(int fd)
{
	char	buf[1];
	char	*line;
	size_t	len;
	ssize_t	r;

	line = NULL;
	len = 0;
	while (1)
	{
		r = read(fd, buf, 1);
		if (r <= 0)
			break ;
		line = append_char_to_line(line, len, buf[0]);
		if (!line)
			return (NULL);
		len++;
		if (buf[0] == '\n')
			break ;
	}
	if (r <= 0 && len == 0)
		return (NULL);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

static void	write_heredoc_line(int write_fd, char *line,
			int should_expand, t_shell *shell)
{
	char	*expanded;

	if (should_expand)
	{
		expanded = expand_variable_in_part(line, shell);
		write(write_fd, expanded, ft_strlen(expanded));
		free(expanded);
	}
	else
		write(write_fd, line, ft_strlen(line));
	write(write_fd, "\n", 1);
}

static char	*get_heredoc_input(void)
{
	char	*line;
	int		tty_fd;

	line = NULL;
	if (isatty(STDIN_FILENO))
		line = readline("> ");
	else
	{
		tty_fd = open("/dev/tty", O_RDONLY);
		if (tty_fd >= 0)
		{
			line = read_line_from_fd(tty_fd);
			close(tty_fd);
		}
		else
			line = read_line_from_fd(STDIN_FILENO);
		if (!line)
			return (NULL);
	}
	return (line);
}

int	heredoc_loop(int write_fd, char *delim, int should_expand,
			t_shell *shell)
{
	char	*line;
	int		lc;

	lc = 0;
	while (1)
	{
		line = get_heredoc_input();
		if (!line)
		{
			if (lc == 0)
				lc = 1;
			printf("%s: warning: here-document at line ", NAME);
			printf("%d delimited by end-of-file (wanted `%s')\n", lc, delim);
			break ;
		}
		lc++;
		if (ft_strcmp(line, delim) == 0)
		{
			free(line);
			break ;
		}
		write_heredoc_line(write_fd, line, should_expand, shell);
		free(line);
	}
	return (0);
}
