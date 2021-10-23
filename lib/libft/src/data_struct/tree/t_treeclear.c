/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_treeclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:43:17 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/22 21:48:17 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_tree.h"

int	ft_treeclear(t_tree *t, void (*del)(void *))
{
	if (!t)
		return (0);
	if (t->leafs)
		ft_treeclear(t->leafs, del);
	if (t->leafs)
		free(t->leafs);
	if (t->next)
		ft_treeclear(t->next, del);
	if (t->next)
		free(t->next);
	ft_lstclear(&(t->content), del);
	free(t);
	return (1);
}
