#include "minishell.h"

void	ft_pwd(void)
{
	print_env_content(mini.env, "PWD", 'n');
	printf("\n");
}

void	ft_exit(char *input)
{
	free_struct(input);
	mini.exit = true;
	write(1, "exit\n", 4);
	kill(mini.pid, SIGINT);
}
