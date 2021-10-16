/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listget_dl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 08:06:36 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/16 10:02:07 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"

void	*ft_listget_dl(const char *key, t_dl_list *l)
{
	while (l && ft_memcmp(key, l->name, ft_strlen(key)))
		l = l->next;
	if (l)
		return (l->content);
	return (NULL);
}
