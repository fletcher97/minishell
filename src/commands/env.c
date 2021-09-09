/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:24:46 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/09 15:06:49 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstnew_pp(char **content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->name = content[0];
	new->content = content[1];
	new->next = NULL;
	return (new);
}

void	ft_lstnode_print(t_list *lst, char *name)
{
	while (1)
	{
		if (!(ft_strncmp(lst->name, name, ft_strlen(name))))
		{
			if (!(ft_strncmp(lst->name, name, ft_strlen(lst->name))))
				printf("Content=|%s|, Name=|%s|, ADD=|%p| Next=|%p|\n",lst->content, lst->name,  lst, lst->next);
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

	x = -1;
	mini->env = NULL;
	while (env[++x] != NULL)
	{
		temp = ft_lstnew_pp(ft_split(env[x], '='));
		ft_lstadd_back(&mini->env,temp);
	}
	return(mini->env);
}

void	ft_env(t_mini *mini)
{
	ft_lstprint(mini->env, 'a');
}
