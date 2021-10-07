/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:31:53 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/07 17:02:36 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "ft_list.h"

void	ft_lstprint(t_dl_list *lst, char type)
{
	t_dl_list	*head;

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
			ft_lstnode_print_dl(lst);
		lst = lst->next;
	}
	lst = head;
}
