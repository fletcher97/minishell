/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnode_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:25:06 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/13 21:45:42 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "ft_list.h"
#include "ft_string.h"

void	ft_lstnode_print(t_dl_list *lst, char *name)
{
	t_dl_list	*head;

	head = lst;
	while (1)
	{
		if (ft_strcmp(lst->name, name))
			printf("Content=|%s|, Name=|%s|, PREV=|%p| ADD=|%p| Next=|%p|\n",
				(char *)lst->content, (char *)lst->name, lst->prev, lst,
				lst->next);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	lst = head;
}
