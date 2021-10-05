/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:22 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/05 22:30:25 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_char(char *s1, char c)
{
	int	x;

	x = 0;
	while (s1[x] && s1[x] != c)
		x++;
	return (x);
}

bool	check_char(char *str, char c)
{
	int	x;

	x = -1;
	if (!str)
		return (0);
	while (str[++x])
	{
		if (str[x] == c)
			return (true);
	}
	return (false);
}

bool	check_env_names(char *name, char *content)
{
	t_list	*head;

	head = g_mini.env;
	while (1)
	{
		if (ft_strcmp(name, g_mini.env->name))
		{
			free(g_mini.env->content);
			g_mini.env->content = content;
			g_mini.env = head;
			return (true);
		}
		if (g_mini.env->next == NULL)
			break ;
		g_mini.env = g_mini.env->next;
	}
	g_mini.env = head;
	return (false);
}

// env_sorted had g_mini as param
int	ft_export(void)
{
	t_list	*head;
	t_list	*temp;
	char	*name;
	char	*content;
	char	*arg;

	head = g_mini.env;
	arg = g_mini.argv[1];
	name = get_name(arg, '=');
	if (!name)
		return (env_sorted());
	if (!check_char(arg, '='))
		return (0);
	content = ft_substr(arg, find_char(arg, '=') + 1, ft_strlen(arg));
	if (!check_env_names(name, content))
	{
		temp = ft_lstnew(content);
		temp->name = name;
		ft_lstadd_back(&g_mini.env, temp);
	}
	g_mini.env = head;
	return (1);
}
