/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:41:30 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/07 14:31:42 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_mini *mini)
{
	char *str;
	t_list	head;

	head = *mini->env;
	str = mini->argv[2];
	while(mini->env)
	{
		if(!(ft_strncmp(str, mini->env->name, ft_strlen(mini->env->name))))
		{
			mini->env->content = str;
			return ;
		}
		mini->env = mini->env->next;
	}
	mini->env = &head;
	ft_lstadd_back(&mini->env, ft_lstnew(mini->argv[1]));
}
