/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:29:42 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/05 22:29:46 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*find_name(t_list *lst, char *str)
{
	while (lst)
	{
		if (ft_strcmp(lst->name, str))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
