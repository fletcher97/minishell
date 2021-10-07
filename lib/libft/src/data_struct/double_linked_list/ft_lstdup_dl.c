/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup_dl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:24:14 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/07 16:48:08 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_norm.h"
#include "ft_stdlib.h"
#include "ft_list.h"

t_dl_list	*ft_lstdup_dl(t_dl_list *lst)
{
	t_dl_list	*new;

	new = (t_dl_list *)malloc(sizeof(t_dl_list));
	if (!new)
		return (NULL);
	new->name = lst->name;
	new->content = lst->content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
