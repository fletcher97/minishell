/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:31:53 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/07 15:21:06 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst, char type)
{
	t_list	*head;

	head = lst;
	while(lst)
	{
		if (type == 'c')
			printf("%s\n", lst->content);
		else if (type == 'n')
			printf("%s\n", lst->name);
		lst = lst->next;
	}
	lst = head;
}
