/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:24:46 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/07 17:45:52 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstnode_print(t_list *lst, char *name)
{
	while (1)
	{
		if (!(ft_strncmp(lst->name, name, ft_strlen(name))))
		{
			printf("Content=|%s|, Name=|%s|, Next=|%p|\n",lst->content, lst->name, lst->next);
		}
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
}

char	*get_name(char *str, char c)
{
	char	*name;
	int 	x;

	x = 0;
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
	while (lst)
	{
		lst->name = get_name(lst->content, '=');
		if (lst->next == NULL)
			break ;
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
//	ft_lstprint(mini->env, 'n');
}
