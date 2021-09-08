#include <stdio.h>
#include <unistd.h>
#include "../includes/libft.h"


int main(int argc, char **argv, char **env)
{
	t_list *envs;
	t_list *head;

	int x = 0;
	if (argc < 1)
		return(0);
	printf("%s\n",argv[1]);
	while (env[x] != NULL)
	{
		envs = ft_lstnew(env[x]);
		ft_lstadd_back(&head,envs);
		envs->next = envs;
	}
}
