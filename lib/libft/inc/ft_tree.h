/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:25 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/22 21:48:35 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_H
# define FT_TREE_H

# include "ft_list.h"

typedef struct s_tree
{
	char			*key;
	t_list			*content;
	struct s_tree	*leafs;
	struct s_tree	*next;
}				t_tree;

t_tree	*ft_treenew(char *key, void *content);

// Add content to current node
int		ft_treeadd(t_tree *tree, void *content);

// Insert on same level
int		ft_treeinsert(t_tree *tree, char *key, void *content);

#endif
