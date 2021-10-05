/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:38 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/05 22:30:41 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	node_free_machine(void)
{
	free(g_mini.env->name);
	free(g_mini.env->content);
	g_mini.env->name = NULL;
	g_mini.env->content = NULL;
	g_mini.env = NULL;
}

bool	lst_str_check(t_list *lst, char *str)
{
	t_list	*head;
	char	*name;

	head = lst;
	while (1)
	{
		name = lst->name;
		if (ft_strcmp(name, str))
		{
			lst = head;
			return (true);
		}
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	lst = head;
	return (false);
}

void	ft_unset(void)
{
	t_list	*head;
	t_list	*temp;
	t_list	*temp2;

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
