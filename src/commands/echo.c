#include "minishell.h"

void	print_env_content(t_list *lst, char *name, char free_name)
{
	char *content;

	content = NULL;
	if (return_env_content(lst, name))
	{
		content = return_env_content(lst, name);
		if (content == NULL)
			printf("\n");
		else
			printf("%s", content);
	}
	if (free_name == 'y')
		free(name);
}

char	*return_env_content(t_list *lst, char *name)
{
	while (lst)
	{
		if (ft_strcmp(lst->name, name))
			break ;
		if (lst->next == NULL)
			return(NULL);
		lst = lst->next;
	}
	return (lst->content);
}

char	*env_flag_check(int i)
{
	char	*env_name;
	int j;

	j = 0;
	env_name = NULL;
	while (mini.argv[i][j])
		j++;
	if (j > 0 && mini.argv[i][0] == '$')
	{
		env_name = ft_substr(mini.argv[i], 1, j);
		return (env_name);
	}
	return (NULL);
}

void	echo_no_flag(int i, int j)
{
	if (i > 1)
	{
		j = 1;
		while (i > j)
		{
			if (env_flag_check(j) != NULL)
				print_env_content(mini.env, env_flag_check(j), 'y');
			else
				printf("%s", mini.argv[j]);
			if (i > 1 + j++)
				printf(" ");
		}
		printf("\n");
	}
}

void	echo_n_flag(int i, int j)
{
	if (i > 2)
	{
		j = 2;
		while (i > j)
		{
			if (env_flag_check(j) != NULL)
				print_env_content(mini.env, env_flag_check(j), 'y');
			else
				printf("%s", mini.argv[j]);
			if (i > 1 + j++)
				printf(" ");
		}
	}
}

void	ft_echo()
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mini.argv[i])
		i++;
	if (i >= 2 && ft_strcmp(mini.argv[1], "-n"))
		echo_n_flag(i, j);
	else
		echo_no_flag(i, j);
}
