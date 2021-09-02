#include "minishell.h"

char    *ft_pwd(void)
{
    char *str;
	str = malloc(sizeof(PATH_MAX));
    getcwd(str, PATH_MAX);

    return (str);
}

void	screening(char* str, int pid)
{
	if (!str)
		return ;
	else if (!ft_strncmp(str, "pwd", ft_strlen(str)))
		printf("%s\n", ft_pwd());
	else if (!ft_strncmp(str, "exit", ft_strlen(str)))
	{
		write(1, "exit", 4);
		kill(pid, SIGINT);
	}
	else
		return ;
}

int main()
{
	char	*inpt;
	int		pid;

	pid = getpid();
	while (42)
	{
		inpt = readline("minishell: ");
		add_history(inpt);
		screening(inpt, pid);
	}
	return (0);
}
