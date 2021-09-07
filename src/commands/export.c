/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:41:30 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/07 17:53:16 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_env_names(t_mini *mini, char *name)
{
	while(1)
	{
		printf("%s %s\n", name, mini->env->name);
		if(!(ft_strncmp(name, mini->env->name, ft_strlen(mini->env->name))))
		{
			printf("%s %s\n", name, mini->env->name);
			mini->env->content = mini->argv[1];
			return (true);
		}
		if (mini->env->next != NULL)
			break ;
		mini->env = mini->env->next;
	}
	return(false);
}

void	ft_export(t_mini *mini)
{
	t_list	*head;
	t_list	*temp;
	char *name;

	head = mini->env;
	name = get_name(mini->argv[1], '=');
	printf("%s %s\n", name, mini->env->name);
	if (!check_env_names(mini, name))
	{
		temp = ft_lstnew(mini->argv[1]);
		temp->name = name;
		ft_lstadd_back(&mini->env, temp);
	}
	mini->env = head;
}
