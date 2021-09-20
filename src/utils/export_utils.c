#include "minishell.h"

t_list	*swap(t_list *B, t_list *A)
{
	t_list *C;
	t_list *D;

	C = B->next;
	D = C->next;
	A->next = B->next;
	C->next = B;
	B->next = D;
	return(B);
}

void	sorter(t_list *lst)
{
	int ret;
	t_list	*temp;

	temp = lst;
	while(lst->next != NULL)
	{
		ret = ft_strncmp(lst->name, lst->next->name, ft_strlen(lst->name));
//		printf("%p %p\n", lst, lst->next);
//		printf("ret = %d %s %s\n",ret,lst->name,lst->next->name);
		if (ret > 0 || (ret == 0 && ft_strlen(lst->name) > ft_strlen(lst->next->name)))
		{
			lst = swap(lst, temp);
//			printf("%p %p\n", lst, lst->next);
			break ;
		}
		temp = lst;
		lst = lst->next;
	}

}

bool	checker(t_list *lst)
{
	int ret;
	t_list *head = lst;
	while (lst->next != NULL)
	{
		ret = ft_strncmp(lst->name, lst->next->name, ft_strlen(lst->name));
		if (ret > 0)
		{
			lst = head;
			return(false);
		}
		lst = lst->next;
	}
	lst = head;
	return(true);
}

t_list *duplicate_node(t_list *lst)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->name = lst->name;
	new->content = lst->content;
	new->next = NULL;
	//printf("%s %s\n", new->name, new->content);
	return (new);
}

t_list *duplicate_list(t_list *lst)
{
	t_list *temp;
	t_list *dup_lst;

	while (lst)
	{
		temp = duplicate_node(lst);
		ft_lstadd_back(&dup_lst, temp);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return(dup_lst);
}

int	env_sorted(t_mini *mini)
{
	t_list	*lst;
	t_list	*head;

	lst = duplicate_list(mini->env);
	head = lst;
//	ft_lstprint(lst, 'a');
	while (!checker(lst))
	{
		sorter(lst);
		lst = head;
	}
	lst = head;
	ft_lstprint(lst, 'a');
	return(1);
}

