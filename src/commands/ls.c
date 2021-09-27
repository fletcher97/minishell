#include "minishell.h"

void	ft_ls(int i)
{
	mini.str = NULL;
	char *path = "/usr/bin/";
	char *total;
	char* argv[3];

	if (!mini.argv[i])
		return ;
	argv[0] = mini.argv[i];
	argv[1] = mini.argv[i + 1];
	argv[2] = NULL;

	if (ft_strcmp(mini.argv[i], "ls"))
	{
		path = "/bin/";
		argv[1] = getcwd(mini.str, PATH_MAX);
	}
	total = ft_strjoin(path, argv[0]);
	if (fork() == 0)
	{
		if ((execve(total, argv, NULL) == -1))
			error_output('c', 0);
		kill(getpid(), SIGINT);
	}
	else
		wait(NULL);
	free(total);
}
