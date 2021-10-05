/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:31:53 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/21 14:09:44 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst, char type)
{
	t_list	*head;

	head = lst;
	while (lst)
	{
		if (type == 'n' || type == 'a')
			printf("%s", lst->name);
		if (type == 'a')
			printf("=");
		if (type == 'c' || type == 'a')
			printf("%s\n", lst->content);
		if (type == 'd')
			ft_lstnode_print_2p(lst);
		lst = lst->next;
	}
	lst = head;
}
