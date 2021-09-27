#include "minishell.h"

void	node_free_machine()
{
	free(mini.env->name);
	free(mini.env->content);
	mini.env->name = NULL;
	mini.env->content = NULL;
	mini.env = NULL;
}

bool	lst_str_check(t_list *lst, char *str)
{
	t_list	*head;
	char	*name;

	head = lst;
	while(1)
	{
		name = lst->name;
		if (ft_strcmp(name, str))
		{
				lst = head;
				return (true);
		}
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	lst = head;
	return (false);
}

void	ft_unset()
{
	t_list	*head;
	t_list	*temp;
	t_list	*temp2;

	head = mini.env;
	temp = NULL;
	if (!(lst_str_check(mini.env, mini.argv[1])))
		return ;
	while (!(ft_strcmp(mini.env->name, mini.argv[1])))
	{
		temp = mini.env;
		mini.env = mini.env->next;
	}
	if (mini.env->next != NULL)
		temp2 = mini.env->next;
	else
		temp2 = NULL;
	temp->next = temp2;
	node_free_machine();
	mini.env = head;
}
