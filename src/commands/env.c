/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:24:46 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/07 14:53:32 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_name(t_list *lst, char c)
{
	char	*name;
	char	*str;
	int 	x;

	x = 0;
	str = lst->content;
	name = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	while (str[x] && str[x] != c)
	{
		name[x] = str[x];
		x++;
	}
	name[x] = '\0';
	return(name);
}

void	env_add_names(t_list *lst)
{
	t_list	*head;

	head = lst;
	while (lst->next != NULL)
	{
		lst->name = get_name(lst, '=');
		lst = lst->next;
	}
	lst = head;
}

t_list	*get_env(char **env, t_mini *mini)
{
	t_list	*temp;
	int x;

	x = 0;
	while (env[x] != NULL)
	{
		temp = ft_lstnew(env[x]);
		ft_lstadd_back(&mini->env,temp);
		x++;
	}
	env_add_names(mini->env);
	return(mini->env);
}

void	ft_env(t_mini *mini)
{
	ft_lstprint(mini->env, 'c');
	ft_lstprint(mini->env, 'n');
}
