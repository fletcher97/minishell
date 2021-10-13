/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnode_print_dl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:24:57 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/13 21:46:14 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "ft_list.h"

void	ft_lstnode_print_dl(t_dl_list *lst)
{
	printf("C= |%s - %p|", (char *)lst->name, lst->name);
	if (lst->prev != NULL)
		printf(" , P= |%s - %p|", (char *)lst->prev->name, lst->prev->name);
	else
		printf(" , P= |null|");
	if (lst->next != NULL)
		printf(" , N= |%s - %p|", (char *)lst->next->name, lst->next->name);
	else
		printf(" , N= |null|");
	printf("\n");
}
