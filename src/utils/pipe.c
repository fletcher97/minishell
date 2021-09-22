#include "minishell.h"

int screening_pipe(int i)
{
	if (ft_strcmp(argv[0], "echo"))
		ft_echo();
}

int	pipe(int i)
{
	int pipefd[2];
	int pid;

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		// Child
		dup2(pipefd[1], 1); // STDOUT para write pipe
		close(pipefd[0]);
		close(pipefd[1]);
		screening_pipe(i);
	}
	else
	{
		wait(NULL);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		close(pipefd[1]);
		screening_pipe(i);
	}
	return(0);
}
