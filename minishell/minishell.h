/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:19:34 by jbdmc             #+#    #+#             */
/*   Updated: 2025/12/15 12:01:31 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _POSIX_C_SOURCE 200809L

// Macros
# define PROMPT "minishell$ "
# define EXIT "exit\n"

// Structs
typedef struct s_global
{
	int		exit_status;
}	t_global;

extern t_global	g_global;

typedef enum e_tokentype
{
	WORD,		// text (echo, cd, ls, hello, file.txt, ...)
	PIPE,		// |
	GREAT,		// >
	DGREAT,		// >>
	LESS,		// <
	DLESS		// <<
}	t_tokentype;

typedef struct s_token
{
	char			*value;
	t_tokentype		type;
	struct s_token	*next;
}	t_token;

// Libraries

# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <signal.h>
# include <dirent.h>
# include <termio.h>
# include <term.h>

// Function Declaration

// cleaning.c:
void	free_all(void);
void	clean_exit(void);

// commands_extra.c:
/* void	ft_unset(t_token **tokens);
void	ft_env(t_token **tokens); */
int		is_valid_n_flag(char *s);

// commands.c:
void	ft_echo(t_token **tokens);
/* void	ft_cd(t_token **tokens);
void	ft_pwd(t_token **tokens);
void	ft_export(t_token **tokens); */
void	get_commands(t_token **tokens);

// echo.c:

// input_handling.c:
int		ft_strisspace(char *line);
char	*read_input(void);

// parsing_helpers.c:
int		parse_pipe(char *line, size_t *i, t_token **tokens);
int		parse_less(char *line, size_t *i, t_token **tokens);
int		parse_great(char *line, size_t *i, t_token **tokens);
int		parse_single_quotes(char *line, size_t *i, t_token **tokens);
int		parse_double_quotes(char *line, size_t *i, t_token **tokens);

// parsing.c:
void	parse_input(char *line, size_t i, t_token **tokens);
int		syntaxe_error(char *line, size_t i);
int		skip_spaces(char *line, size_t *i);

// setup_signal_handlers.c:
void	sigint_handler(int sig);
void	setup_signal_handlers(void);

// tokenization.c:
void	add_token(char *value, t_tokentype type, t_token **tokens);

// temp
void	print_tokens(t_token *tokens);

#endif