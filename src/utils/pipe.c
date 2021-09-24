#include "minishell.h"

int screening_pipe(int i)
{
	if (mini.argv)
	{
		if (ft_strcmp(mini.argv[i], "pwd"))
			ft_pwd();
		else if (ft_strcmp(mini.argv[i], "echo"))
			ft_echo();
		else if (ft_strcmp(mini.argv[i], "cd"))
			ft_cd();
		else if (ft_strcmp(mini.argv[i], " "))
			printf("\n");
		else if(ft_strcmp(mini.argv[i], "env"))
				ft_env();
		else if(ft_strcmp(mini.argv[i], "export"))
			ft_export();
		else if (ft_strcmp(mini.argv[i], "unset"))
			ft_unset();
		else
			ft_ls(i);
	}
	return (i);
}

int	piper(int i)
{
	int pipefd[2];
	int pid;

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		// Child
		dup2(pipefd[1], STDOUT_FILENO); // STDOUT para write pipe
		close(pipefd[0]);
		close(pipefd[1]);
		screening_pipe(--i);
	}
	else
	{
		wait(NULL);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		screening_pipe(i++);
	}
	return(0);
}
