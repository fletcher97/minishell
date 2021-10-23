/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:16:41 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/22 20:37:50 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"

int	ft_treeinsert(t_tree *tree, char *key, void *content)
{
	if (!tree)
		return (-1);
	while (tree->next)
		tree = tree->next;
	tree->next = ft_treenew(key, content);
	if (!tree->next)
		return (0);
	return (1);
}
