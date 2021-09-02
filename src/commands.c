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
	if (!ft_strncmp(str + 5, "-n ", 3))
		printf("%s", str + 8);
	else
		printf("%s\n", str + 5);
}
