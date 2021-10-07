/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_dl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:24:48 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/07 16:48:35 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_norm.h"
#include "ft_stdlib.h"
#include "ft_list.h"

t_dl_list	*ft_lstnew_dl(char **content)
{
	t_dl_list	*new;

	new = (t_dl_list *)malloc(sizeof(t_dl_list));
	if (!new)
		return (NULL);
	new->name = content[0];
	new->content = content[1];
	new->next = NULL;
	return (new);
}
