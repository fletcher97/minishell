#include <stdio.h>
#include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>

char    *ft_pwd(void)
{
    char *str;
	str = malloc(sizeof(PATH_MAX));
    getcwd(str, PATH_MAX);

    return (str);
}


int main()
{
	char	*inpt;
	char	*path;
	while (42)
	{
		path = ft_pwd();
		inpt = readline(path);
		//inpt = readline("Input: ");
		add_history(inpt);
		printf("%s", inpt);
		printf("\n");
	}
	printf("a\n");
	return (0);
}
