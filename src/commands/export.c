/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:22 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/12 16:47:45 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

static int	find_char(char *s1, char c)
{
	int	x;

	x = 0;
	if (!s1)
		return (x);
	while (s1[x] && s1[x] != c)
		x++;
	return (x);
}

int	check_env_names(char *name, char *content)
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
			return (1);
		}
		if (g_mini.env->next == NULL)
			break ;
		g_mini.env = g_mini.env->next;
	}
	g_mini.env = head;
	return (0);
}

//The simple export call will list all our internal environmental variable,
//ordered alphabetically.
int	ft_export(char **argv)
{
	t_dl_list	*head;
	t_dl_list	*temp;
	char		*content[2];
	char		*arg;

	head = g_mini.env;
	arg = argv[1];
	content[0] = get_name(arg, '=');
	if (!content[0])
		return (env_sorted());
	if (!find_char(arg, '='))
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
