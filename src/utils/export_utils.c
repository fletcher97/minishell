/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:57:27 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/07 17:16:15 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	swap(t_dl_list *a, t_dl_list *b, t_dl_list *c)
{
	t_dl_list	*d;

	d = c->next;
	if (a != NULL)
		a->next = c;
	c->next = b;
	b->next = d;
	b->prev = c;
	c->prev = a;
	if (d != NULL)
		d->prev = b;
}

void	sorter(t_dl_list *lst)
{
	int	ret;

	while (lst->next != NULL)
	{
		ret = ft_strncmp(lst->name, lst->next->name, ft_strlen(lst->name));
		if (ret > 0 || (ret == 0
				&& ft_strlen(lst->name) > ft_strlen(lst->next->name)))
		{
			swap(lst->prev, lst, lst->next);
			break ;
		}
		lst = lst->next;
	}
}

bool	checker(t_dl_list *lst)
{
	int	ret;

	while (lst->next != NULL)
	{
		ret = ft_strncmp(lst->name, lst->next->name, ft_strlen(lst->name));
		if (ret > 0)
			return (false);
		lst = lst->next;
	}
	return (true);
}

t_dl_list	*duplicate_list(t_dl_list *lst)
{
	t_dl_list	*temp;
	t_dl_list	*dup_lst;

	dup_lst = NULL;
	while (lst)
	{
		temp = ft_lstdup_dl(lst);
		ft_lstadd_back_dl(&dup_lst, temp);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (dup_lst);
}

int	env_sorted(void)
{
	t_dl_list	*lst;

	lst = duplicate_list(g_mini.env);
	while (!checker(lst))
	{
		sorter(lst);
		lst = ft_lsthead_dl(lst);
	}
	ft_lstprint(lst, 'a');
	if (lst)
		free_dp_list(lst);
	return (1);
}
