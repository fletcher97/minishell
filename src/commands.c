#include "minishell.h"

void	ft_pwd(void)
{
	printf("%s\n", pwd());
}

void	ft_exit(int pid)
{
	write(1, "exit", 4);
	kill(pid, SIGINT);
}

void	ft_echo(char *str)
{
	if (!ft_strncmp(str + 4, " ", 1))
	{
		if (!ft_strncmp(str + 5, "-n", 2))
		{
			if (!ft_strncmp(str + 4, " ", 1))
				printf("%s", str + 8);
			else
				return ;
		}
		else
			printf("%s\n", str + 5);
	}
	else
		printf("\n");
}

void	ft_cd(void)
{
	char	*str;
	char	*path;
	path = NULL;

	str = getenv("DESKTOP");
	printf("%s\n", str);
}
