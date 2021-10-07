/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:22 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/07 18:01:10 by fferreir         ###   ########.fr       */
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
	t_dl_list	*head;

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
	t_dl_list	*head;
	t_dl_list	*temp;
	char		*content[2];
	char		*arg;

	head = g_mini.env;
	arg = g_mini.argv[1];
	content[0] = get_name(arg, '=');
	if (!content[0])
		return (env_sorted());
	if (!check_char(arg, '='))
		return (0);
	content[1] = ft_substr(arg, find_char(arg, '=') + 1, ft_strlen(arg));
	if (!check_env_names(content[0], content[1]))
	{
		temp = ft_lstnew_dl(content);
		ft_lstadd_back_dl(&g_mini.env, temp);
	}
	g_mini.env = head;
	return (1);
}
