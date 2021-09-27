#include "minishell.h"

void	error_output(char type, int i)
{
	if (i < 0)
		i = 0;
	if (type == 'c')
		printf("minishell: command not found: %s\n", mini.argv[i]);
	if (type == 's')
		printf("minishell: special character not define: %s\n", mini.argv[i]);
}

