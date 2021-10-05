#include "libft.h"

void	ft_lstnode_print(t_list *lst, char *name)
{
	t_list	*head;

	head = lst;
	while (1)
	{
		if (ft_lencmp(lst->name, name))
			printf("Content=|%s|, Name=|%s|, PREV=|%p| ADD=|%p| Next=|%p|\n",
				lst->content,lst->name, lst->prev, lst, lst->next);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	lst = head;
}
