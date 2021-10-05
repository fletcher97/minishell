#include "libft.h"

void	ft_lstnode_print_2p(t_list *lst)
{
	if (lst->prev != NULL && lst->next !=NULL)
		printf("C= |%s - %p| , P= |%s - %p| , N= |%s - %p|\n",
			lst->name, lst, lst->prev->name, lst->prev, lst->next->name, lst->next);
	if (lst->prev == NULL && lst->next != NULL)
		printf("C= |%s - %p| , P= |%p| , N= |%s - %p|\n",
			lst->name, lst, lst->prev, lst->next->name, lst->next);
	if (lst->prev != NULL && lst->next == NULL)
		printf("C= |%s - %p| , P= |%s - %p| , N= |%p|\n",
			lst->name, lst, lst->prev->name, lst->prev, lst->next);
}
