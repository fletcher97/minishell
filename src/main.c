#include "minishell.h"
char    *ft_pwd(void)
{
    char *str;
	str = malloc(sizeof(PATH_MAX));
    getcwd(str, PATH_MAX);

    return (str);
}

void	screening(char* str)
{
	if (!str)
		return ;
	else if (!ft_strncmp(str, "pwd", ft_strlen(str)))
		printf("%s", ft_pwd());
	printf("\n");
}

int main()
{
	char	*inpt;

	while (42)
	{
		inpt = readline("minishell: ");
		add_history(inpt);
		screening(inpt);
	}
	printf("a\n");
	return (0);
}
