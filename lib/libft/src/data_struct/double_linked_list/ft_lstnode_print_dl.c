/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnode_print_dl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:24:57 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/07 19:47:17 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "ft_list.h"

void	ft_lstnode_print_dl(t_dl_list *lst)
{
	printf("C= |%s - %p|", lst->name, lst->name);
	if (lst->prev != NULL)
		printf(" , P= |%s - %p|", lst->prev->name, lst->prev->name);
	else
		printf(" , P= |null|");
	if (lst->next != NULL)
		printf(" , N= |%s - %p|", lst->next->name, lst->next->name);
	else
		printf(" , N= |null|");
	printf("\n");
}
