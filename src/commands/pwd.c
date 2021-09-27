#include "minishell.h"

char	*pwd(void)
{
	char *str;

	str = NULL;
	str = getcwd(str, PATH_MAX);
	return (str);
}

void	ft_pwd(void)
{
	printf("%s\n", pwd());
}

void	ft_exit(char *input)
{
	free_struct(input);
	mini.exit = true;
	write(1, "exit\n", 4);
	kill(mini.pid, SIGINT);
}
