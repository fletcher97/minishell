/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:10 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/07 18:24:21 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_name(char *str, char c)
{
	char	*name;
	int		x;

	x = -1;
	if (!str)
		return (NULL);
	name = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	while (str[++x] && str[x] != c)
		name[x] = str[x];
	name[x] = '\0';
	return (name);
}

// Something ...
// Or other
void	env_add_names(t_dl_list *lst)
{
	t_dl_list	*head;

	head = lst;
	while (lst)
	{
		lst->name = get_name(lst->content, '=');
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	lst = head;
}

t_dl_list	*get_env(char **env)
{
	t_dl_list	*temp;
	int			x;

	x = -1;
	g_mini.env = NULL;
	while (env[++x] != NULL)
	{
		temp = ft_lstnew_dl(ft_split(env[x], '='));
		ft_lstadd_back_dl(&g_mini.env, temp);
	}
	return (g_mini.env);
}

void	ft_env(void)
{
	ft_lstprint(g_mini.env, 'a');
}
