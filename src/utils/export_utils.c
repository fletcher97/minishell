#include "minishell.h"

void	swap(t_list *A, t_list *B, t_list *C)
{
	t_list *D;

	D = C->next;
	if (A != NULL)
		A->next = C;
	C->next = B;
	B->next = D;
	B->prev = C;
	C->prev = A;
	if (D != NULL)
		D->prev = B;
}

void	sorter(t_list *lst)
{
	int ret;

	while(lst->next != NULL)
	{
		ret = ft_strncmp(lst->name, lst->next->name, ft_strlen(lst->name));

		if (ret > 0 || (ret == 0 && ft_strlen(lst->name) > ft_strlen(lst->next->name)))
		{
			swap(lst->prev, lst, lst->next);
			break ;
		}
		lst = lst->next;
	}

}

bool	checker(t_list *lst)
{
	int ret;
	while (lst->next != NULL)
	{
		ret = ft_strncmp(lst->name, lst->next->name, ft_strlen(lst->name));
		if (ret > 0)
			return(false);
		lst = lst->next;
	}
	return(true);
}

t_list *duplicate_list(t_list *lst)
{
	t_list *temp;
	t_list *dup_lst;

	dup_lst = NULL;
	while (lst)
	{
		temp = ft_lstdup_2p(lst);
		ft_lstadd_back_2p(&dup_lst, temp);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return(dup_lst);
}

int	env_sorted()
{
	t_list	*lst;

	lst = duplicate_list(mini.env);
	while (!checker(lst))
	{
		sorter(lst);
		lst = ft_lsthead_2p(lst);
	}
	ft_lstprint(lst, 'a');
	if (lst)
		free_dp_list(lst);
	return(1);
}
