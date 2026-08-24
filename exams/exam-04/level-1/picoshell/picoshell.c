#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

/* Objective:
** the function must execute a pipeline. 
** It must execute each shell command passed to it and connect the output of one to the input of another (just like a shell).
** In case of error, the function must return 1, closing all open file descriptors before doing it.
** Otherwise, the function must wait for all child processes to end their activity and then return 0.
** Allowed functions: close, fork, wait, exit, execvp, dup2, pipe.
** File descriptors CANNOT be leaked.
*/

int	picoshell(char **cmds[]) {
	
	// check command list
	if (!cmds)
		return (1);
	
	int		fd[2];					// pipe ends (READ [0], WRITE [1])
	int		in_fd = STDIN_FILENO;	// starts on the standard STDIN
	pid_t	pid;					// initialize pid for convenience

	// iterate through all commands
	for (int i = 0; cmds[i]; i++)
	{
		// creating the pipe for each command
		if (cmds[i + 1])	// check if there is any command after the current one, because if not we don't need a pipe
		{
			if (pipe(fd) == -1)		// in case of error while creating the pipe
			{
				if (in_fd != STDIN_FILENO)	// if the in_fd is not the standard STDIN (which means it is the output of another fd)
					close(in_fd);			// close it to prevent leaks
				return (1);
			}
		}
		else	// in case there is no command after the current one
		{
			fd[0] = -1;		// no need for a pipe so we just set the FDs to -1 (invalid)
			fd[1] = -1;
		}

		// making the fork for each command
		pid = fork();		// set the parent/child pids
		if (pid == -1)		// in case an error occurs while making the fork
		{
			if (in_fd != STDIN_FILENO)	// same reason as before
				close(in_fd);
			if (fd[0] != -1)			// check if there is a pipe (in this case something connected to the read side of it)
				close(fd[0]);
			if (fd[1] != -1)			// check if there is a pipe (in this case something connected to the write side of it)
				close(fd[1]);
			return (1);
		}

		// managing the child process
		else if (pid == 0)
		{
			// dup the process
			if (fd[0] != -1)	// the child never needs the READ end of the pipe it is creating for its own stdout
				close(fd[0]);
			if (in_fd != STDIN_FILENO)	// if there is a pipe before this process (will read from a file output)
			{
				if (dup2(in_fd, STDIN_FILENO) == -1)	// STDIN (fd = 0) will now read from in_fd | if dup2 returns -1 there was an error on the input-output connection
				{
					close(in_fd);		// close the in_fd
					if (fd[1] != -1)	// if there was no fd assigned to write to
						close(fd[1]);
					exit(1);			// close the child process immediately
				}
				close(in_fd);	// close the in_fd since we now connected STDIN to read from the same spot as it was reading
			}
			if (fd[1] != -1)	// in case there is no fd assigned to write to
			{
				if (dup2(fd[1], STDOUT_FILENO) == -1)	// child process will now write to STDOUT (fd = 1) | if dup2 returns -1 there was an error on the input-output connection
				{
					close(fd[1]);	// closes the write fd
					exit(1);		// close the child process immediately
				}
				close(fd[1]);	// close the write fd since we now connected STDOUT to where the process was writting
			}

			// execute the process
			execvp(cmds[i][0], cmds[i]);	// executes the current command from the start (cmds[i][0]) with the arguments being itself
			exit(1);						// in case the execution fails, close the child process immediately
		}

		// managing the parent process
		if (in_fd != STDIN_FILENO)	// *I got confused here*
			close(in_fd);
		if (fd[1] != -1)
			close(fd[1]);
		in_fd = fd[0];
	}

	// wait for the children
	int status;
	while (wait(&status) != -1)	// wait for any child process running to finish
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)	// *I got confused here*
			return (1);
		if (WIFSIGNALED(status))							// *I got confused here*
			return (1);
	}
	if (errno != ECHILD)	// *I got confused here*
		return (1);
	return (0);
}

int	main() {

}