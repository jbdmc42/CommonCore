/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:19:34 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:42:00 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _POSIX_C_SOURCE 200809L

// Macros

# define NAME "minishell"
# define PROMPT "minishell$ "
# define EXIT "exit\n"

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
# include <limits.h>

// Globals
extern volatile sig_atomic_t	g_signal_received;

// Structs

/*
** Environment Variables Structure that holds the content of
** all the environment variables on our program
*/

typedef struct s_env
{
	char				*name;
	char				*val;
	struct s_env		*prev;
	struct s_env		*next;
}	t_env;

/*
** Shell state structure that holds the shell's context
** int exit_status: last command exit status (for $? and error codes)
*/
typedef struct s_shell
{
	int		exit_status;
	t_env	*env;	
	int		saved_stdin;
	int		saved_stdout;
	int		redirs_saved;
}	t_shell;

// More Structs

/* 
**  enumeration of types that a token can have/be
** WORD  : text (echo, cd, ls, hello, file.txt, ...)
** PIPE  : |
** GREAT : >
** DGREAT: >>
** LESS  : <
** DLESS : <<
*/
typedef enum e_tokentype
{
	WORD,
	PIPE,
	GREAT,
	DGREAT,
	LESS,
	DLESS,
}	t_tokentype;

/* 
**  char 	      *value: actual value of the token in a string
**  t_tokentype 	type: the type of the token based on the list of token types 
** (and that's why we use t_tokentype)
**  struct s_token *next: a pointer to the next node in the token struct so we 
** can "travel" inside it
*/
typedef struct s_token
{
	char			*value;
	t_tokentype		type;
	struct s_token	*next;
	int				heredoc_fd;
}	t_token;

typedef struct s_pipe_ctx
{
	t_token	*tokens;
	t_token	*cmd;
	t_token	*next_token;
	t_shell	*shell;
	int		num_cmds;
	int		i;
	int		pipe_fd[2];
	int		prev_read_fd;
	int		status;
	int		child_count;
	pid_t	pid;
	pid_t	last_pid;
}	t_pipe_ctx;

typedef struct s_exec_ctx
{
	char	**argv;
	char	**envp;
	t_shell	*shell;
}	t_exec_ctx;

typedef struct s_redir_process_ctx
{
	t_token	**tokens;
	t_shell	*shell;
	int		*pending_stdin_fd;
	t_token	**next;
	int		saved_stdin;
	int		saved_stdout;
}	t_redir_process_ctx;

typedef struct s_heredoc_ctx
{
	pid_t				pid;
	int					status;
	struct sigaction	old_int;
	struct sigaction	old_quit;
	int					pipe_fd[2];
	char				*delimiter;
	int					should_expand;
	t_shell				*shell;
}	t_heredoc_ctx;

// Function Declaration

// main_helpers.c:
int		process_input_line(char **line, t_shell *shell);
void	execute_line(char *line, t_shell *shell, int interactive);
int		run_interactive_cycle(t_shell *shell);
int		run_noninteractive_cycle(t_shell *shell);
void	main_loop(t_shell *shell, int interactive);

// main.c:
size_t	skip_blank_prefix(char *line);
void	execute_line(char *line, t_shell *shell, int interactive);

// cleaning.c:
void	clean_exit(t_shell *shell);

// commands.c:
void	ft_echo(t_token *tokens, t_shell *shell);
void	ft_exit(t_token *tokens, t_shell *shell);
int		ft_cd(t_token *tokens, t_shell *shell);
void	ft_pwd(t_shell *shell);
void	ft_export(t_token *tokens, t_shell *shell);
int		ft_unset(t_token *tokens, t_shell *shell);
void	get_commands(t_token *tokens, t_shell *shell);
char	**build_argv(t_token *tokens);
int		count_tokens_for_argv(t_token *tokens);
char	**build_envp(t_shell *shell);
void	free_envp_array(char **envp);
void	cleanup_redirections(t_shell *shell);
void	store_saved_redirections(t_shell *shell, int saved_stdin,
			int saved_stdout);
int		setup_redirections(t_token **tokens, int *saved_stdin,
			int *saved_stdout, t_shell *shell);
void	restore_redirections(int saved_stdin, int saved_stdout);
int		search_and_execute(char *command, char **argv,
			char **envp, t_shell *shell);

// helpers moved from commands.c
int		is_builtin_command(char *cmd);
void	execute_builtin(t_token *tokens, t_shell *shell);

// pipes_helpers.c:
int		execute_pipe_chain(t_token *tokens, t_shell *shell);
int		pre_create_heredocs(t_pipe_ctx *ctx);

// pipes_helpers_two.c:
void	init_pipe_ctx(t_pipe_ctx *ctx, t_token *tokens, t_shell *shell);
void	setup_pipe_child(t_pipe_ctx *ctx);
int		run_pipe_stage(t_pipe_ctx *ctx);
int		handle_pipe_fork_error(t_pipe_ctx *ctx);
int		wait_pipe_children(t_pipe_ctx *ctx);

// pipes_helpers_three.c (moved helpers)
void	free_inherited_resources(t_pipe_ctx *ctx);
void	child_dup_fds(t_pipe_ctx *ctx);
void	child_finish(t_pipe_ctx *ctx);
int		create_pipe_if_needed(t_pipe_ctx *ctx);
void	post_parent_housekeeping(t_pipe_ctx *ctx);

// pipes.c:
int		count_commands(t_token *tokens);
t_token	*extract_command(t_token *tokens, t_token **next_token);
int		create_pipe(int *pipe_fd);
void	close_fd(int *fd);

// echo.c:
void	ft_echo(t_token *tokens, t_shell *shell);

// exit.c:
void	ft_exit(t_token *tokens, t_shell *shell);

// export_helpers.c:
int		fill_node(t_env *var, char *name, char *val, t_env *cur);
void	redefine_value(t_shell *shell, char **nameval, int is_append);
void	define_value(t_shell *shell, char *name, char *val);
char	**split_export_arg(char *arg, int *is_append);
void	print_env(t_shell *shell);
void	parse_argument(t_token *tokens, t_shell *shell);

// export.c:
char	**alpha_sort(t_shell *shell);
void	ft_export(t_token *tokens, t_shell *shell);
void	process_export_var(char **nameval, t_shell *shell, int is_append);

// env.c:
void	ft_env(t_token *tokens, t_shell *shell);

// ft_getline.c:
ssize_t	ft_getline_fd(char **lineptr, size_t *n, int fd);

// ft_lsttochpp.c:
char	**ft_lsttochpp(char **chpp, t_env *env);
char	**ft_lsttochpp_no_quotes(char **chpp, t_env *env);

// input_handling.c:
int		ft_strisspace(char *line);
char	*read_input(void);

// quote_handling.c:
int		is_quotes_balanced(char *str);
char	*read_input_with_continuation(char *line, t_shell *shell);

// parsing_helpers.c:
int		parse_pipe(char *line, size_t *i, t_token **tokens, t_shell *shell);
int		parse_less(char *line, size_t *i, t_token **tokens, t_shell *shell);
int		parse_great(char *line, size_t *i, t_token **tokens, t_shell *shell);
int		parse_single_quotes(char *line, size_t *i, t_token **tokens);
int		parse_double_quotes(char *line, size_t *i, t_token **tokens);

// parsing_helpers_two/three.c:
char	*ft_strjoin_free(char *a, char *b);
int		is_operator_char(char c);
char	*expand_variable_in_part(char *part, t_shell *shell);
char	*extract_word_part(char *line, size_t *i, t_shell *shell);
int		append_word_part(char **token, char *part);

// redir helpers
int		ft_mkstemp(char *template);
int		*ft_mkstemp_fd(void);
char	*ft_mkstemp_path(void);
void	ft_store_mkstemp_path(char *template, int fd);
char	*ft_get_mkstemp_path(int fd);
void	ft_clear_mkstemp_path(void);
int		ft_lseek(int fd, off_t offset, int whence);
int		create_heredoc_fd(char *delimiter, int should_expand, t_shell *shell);
int		create_tmp_heredoc_fd(void);
void	run_heredoc_child(int tmp_fd, char *delimiter,
			int should_expand, t_shell *shell);
int		finalize_heredoc_parent(int status, int tmp_fd, t_shell *shell);
int		perform_dup2_and_close(int fd, int target_fd, t_shell *shell);
void	close_saved_redirections_in_child(t_shell *shell);
void	set_heredoc_parent_signals(struct sigaction *old_int,
			struct sigaction *old_quit);
void	restore_heredoc_parent_signals(struct sigaction *old_int,
			struct sigaction *old_quit);
int		wait_heredoc_child(pid_t pid, int *status);
int		should_expand_heredoc(const char *delimiter);
void	cleanup_dless_nodes(t_token **tokens, t_token *redir,
			t_token *target);
int		apply_input_redirection(t_token **tokens, t_token *redir,
			t_token *target, t_shell *shell);
int		apply_redir_by_type(t_token **tokens, t_token *redir,
			t_token *target, t_shell *shell);
int		handle_one_redirection(t_token **tokens, t_token *redir,
			t_shell *shell);
int		process_token_redirections(t_token **tokens, t_shell *shell,
			int saved_stdin, int saved_stdout);
int		heredoc_loop(int write_fd, char *delimiter, int should_expand,
			t_shell *shell);
int		check_target_valid(t_token *target, t_shell *shell);
int		apply_redirection_stdin(t_token **tokens, t_token *redir,
			t_token *target, t_shell *shell);
int		apply_redirection_stdout(t_token **tokens, t_token *redir,
			t_token *target, t_shell *shell);
void	unlink_token_node(t_token **tokens, t_token *node, t_token *next);

// commands_extra helpers
int		exec_found_command(char *full_path, char *command, t_exec_ctx *ctx);
int		exec_direct_path(char *command, t_exec_ctx *ctx);
int		try_exec_in_path(char *path_copy, char *command, t_exec_ctx *ctx);

// exec_error.c
void	print_exec_error(char *command);

// parsing.c:
void	parse_input(char *line, size_t i, t_token **tokens, t_shell *shell);
int		syntaxe_error(char *line, size_t i);
int		skip_spaces(char *line, size_t *i);
void	parse_word(char *line, size_t *i, t_token **tokens, t_shell *shell);
char	*env_get_value(t_env *env, const char *name);

// setup_signal_handlers.c:
void	sigint_handler(int sig);
void	setup_signal_handlers(int interactive);

// tokenization.c:
void	add_token(char *value, t_tokentype type, t_token **tokens);
void	print_tokens(t_token *tokens);
void	free_tokens(t_token *tokens);

// utilities_three.c:
int		env_lstsize(t_env *env);
t_env	*get_env_node(t_env *env_list, char *key);
void	free_shell_env(t_shell *shell);

// utilities_two.c:
void	ft_swap(char **a, char **b);
char	*remove_quotes(char *nameval);
void	process_nameval_quotes(char **nameval);
int		is_valid_var_name(char *name);
void	free_nameval(char **nameval);

// utilities.c:
void	init_env(t_shell *shell, char **envp);

#endif