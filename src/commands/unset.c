/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:38 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/11 19:09:12 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

static void	node_free_machine(void)
{
	free(g_mini.env->name);
	free(g_mini.env->content);
	g_mini.env->name = NULL;
	g_mini.env->content = NULL;
	g_mini.env = NULL;
}

static int	lst_str_check(t_dl_list *lst, char *str)
{
	t_dl_list	*head;
	char		*name;

	head = lst;
	while (1)
	{
		name = lst->name;
		if (ft_strcmp(name, str))
		{
			lst = head;
			return (1);
		}
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	lst = head;
	return (0);
}

void	ft_unset(void)
{
	t_dl_list	*head;
	t_dl_list	*temp;
	t_dl_list	*temp2;

	head = g_mini.env;
	temp = NULL;
	if (!(lst_str_check(g_mini.env, g_mini.argv[1])))
		return ;
	while (!(ft_strcmp(g_mini.env->name, g_mini.argv[1])))
	{
		temp = g_mini.env;
		g_mini.env = g_mini.env->next;
	}
	if (g_mini.env->next != NULL)
		temp2 = g_mini.env->next;
	else
		temp2 = NULL;
	temp->next = temp2;
	node_free_machine();
	g_mini.env = head;
}
