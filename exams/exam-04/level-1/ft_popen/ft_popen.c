#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

/* Objective:
** the function must launch the executable file with the arguments argv (using execvp).
** If type is 'r' the function must return a file descriptor connected to the output of the command.
** If type is 'w' the function must return a file descriptor connected to the input of the command.
** In case of error or invalid parameter the function must return -1.
** Allowed functions: pipe, fork, dup2, execvp, close, exit.
** File descriptors CANNOT be leaked.
*/

int		ft_popen(const char *file, char *const argv[], char type)
{
	// pointer check: if there's no file, no arguments, or no specified type (read/write) (since pipes are unidirectional, default popen can only open a file with arguments for read or write, never both)
	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);		// return error value '-1'

	// pipe
	int	fd[2];
	if (pipe(fd) == -1)		// if an error occurs on the pipe
		return (-1);		// return error value '-1'
	
	// process fork
	pid_t	pid = fork();
	if (pid == -1)			// if an error occurs on the fork process
	{
		close(fd[0]);		// close all open file descriptors to prevent leaks
		close(fd[1]);
		return (-1);		// return error value '-1'
	}

	// child process
	if (pid == 0)
	{
		// dup file descriptor
		if (type == 'r')
		{
			close(fd[0]);
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				exit (-1);
			close(fd[1]);
		}
		else if (type == 'w')
		{
			close(fd[1]);
			if (dup2(fd[0], STDIN_FILENO) == -1)
				exit (-1);
			close(fd[0]);
		}

		// execvp
		execvp(file, argv);
		exit(-1);
	}

	// parent process
	if (type == 'r')
	{
		close(fd[1]);
		return (fd[0]);
	}
	close(fd[0]);
	return (fd[1]);
}

// 'main' has to be sent commented, so using strlen is allowed since it is not part of the exercise
int		main()
{
	char	line[1001];
	int		fd = ft_popen("ls", (char *const[]){"ls", NULL}, 'r');
	int		len = read(fd, line, 1000);

	line[len] = '\0';
	write(STDOUT_FILENO, line, strlen(line));
	close(fd);
	return (0);
}