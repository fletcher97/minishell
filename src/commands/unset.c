/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:48:40 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/07 12:40:22 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_mini *mini)
{
	t_list	*head;
	t_list	*temp;
	t_list	*temp2;
	char	*str;

	head = mini->env;
	temp = NULL;
	str = ft_strjoin(mini->argv[1], "=");
	while (ft_strncmp(str, mini->env->content, ft_strlen(str)))
	{
		temp = mini->env;
		mini->env = mini->env->next;
	}
	if(mini->env->next != NULL)
		temp2 = mini->env->next;
	else
		temp2 = NULL;
	temp->next = temp2;
	free(mini->env);
	free(str);
	mini->env = head;
}
