/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:19:24 by jbdmc             #+#    #+#             */
/*   Updated: 2025/12/15 15:30:09 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global g_global;

/* static void	free_tokens(t_token *tokens)
{
	
} */

static size_t	treat_empty_input(char *line, size_t i)		// empty line or the line only contains spaces/tabs
{
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}

static void	main_loop(void)
{
	char	*line;		// variable that will store the user input
	size_t	i;			// counter
	t_token	*tokens;

	while (1)					// main loop (heart of the shell)
	{
		i = 0;
		line = read_input();			// gets the input if no Ctrl + D, EOF or exit command exists and the line is not empty or contains anything more than spaces / tabs
		if (!line)						// if the line comes back as a Ctrl + D, EOF or exit command, we cleanly end the program
			clean_exit();				// frees everything and sets the exit status to 1
		if (line[treat_empty_input(line, i)] == '\0')			// if the line is empty, we skip the loop and restart it
		{
			free(line);
			continue ;
		}
		tokens = NULL;
		parse_input(line, i, &tokens);			// turn the line into tokens
		/* print_tokens(tokens); */
		//free_tokens(tokens);					// free the tokens
		free(line);								// free the line for the next read
	}
}

int	main(int argc, char **argv, char **envp)	// argc > number of arguments (including the program itself) | argv > arguments that we will put into tokens | envp > arguments that we will put into environment variables
{
	(void)argc;			// this is used to tell the compiler that the variable exists, but will not be used here
	(void)argv;
	(void)envp;

	g_global.exit_status = 0;
	setup_signal_handlers();	// prepare the signal handlers to "listen" to the user's input
	main_loop();
	return (g_global.exit_status);	// returns with the exit status (1)
}
