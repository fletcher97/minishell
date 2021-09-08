/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:41:30 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/08 16:21:48 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int find_char(char *s1, char c)
{
	int x;

	x = 0;
	while(s1[x] && s1[x] != c)
		x++;
	return(x);
}

bool	check_env_names(t_mini *mini, char *name, char *content)
{
	while(1)
	{
	//	printf("%s %s\n", name, mini->env->name);
		if(!(ft_strncmp(name, mini->env->name, ft_strlen(mini->env->name))))
		{
			free(mini->env->content);
			mini->env->content = content;
			return (true);
		}
		if (mini->env->next == NULL)
			break ;
		mini->env = mini->env->next;
	}
	return(false);
}

void	ft_export(t_mini *mini)
{
	t_list	*head;
	t_list	*temp;
	char	*name;
	char	*content;
	char	*arg;

	head = mini->env;
	arg = mini->argv[1];
	name = get_name(arg, '=');
	content = ft_substr(arg, find_char(arg,'=') + 1, ft_strlen(arg));
	if (!check_env_names(mini, name, content))
	{
		temp = ft_lstnew(content);
		temp->name = name;
		ft_lstadd_back(&mini->env, temp);
	}
	mini->env = head;
}
