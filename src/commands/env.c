/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:24:46 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/21 17:15:36 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_name(char *str, char c)
{
	char	*name;
	int 	x;

	x = -1;
	if (!str)
		return(NULL);
	name = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	while (str[++x] && str[x] != c)
		name[x] = str[x];
	name[x] = '\0';
	return(name);
}

void	env_add_names(t_list *lst)
{
	t_list	*head;

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

t_list	*get_env(char **env)
{
	t_list	*temp;
	int x;

	x = -1;
	mini.env = NULL;
	while (env[++x] != NULL)
	{
		temp = ft_lstnew_pp(ft_split(env[x], '='));
		ft_lstadd_back(&mini.env,temp);
	}
	return(mini.env);
}

void	ft_env()
{
	ft_lstprint(mini.env, 'a');
}
