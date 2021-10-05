#include "libft.h"

t_list	*ft_lstnew_pp(char **content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->name = content[0];
	new->content = content[1];
	new->next = NULL;
	return (new);
}
