/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:48:40 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/07 17:26:32 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	lst_str_check(t_list *lst, char *str)
{
	t_list	*head;
	char	*name;
	int		x;

	head = lst;
	ft_lstprint(lst, 'n');
	while(1)
	{
		name = lst->name;
		x = ft_strlen(name) - ft_strlen(str);;
		if (!(ft_strncmp(str,name, ft_strlen(name))) && x == 0)
		{
				lst = head;
				printf("%s %s\n", str, name);
				return (true);
		}
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	lst = head;
	return (false);
}

void	ft_unset(t_mini *mini)
{
	t_list	*head;
	t_list	*temp;
	t_list	*temp2;
	char	*str;

	head = mini->env;
	temp = NULL;
	str = mini->argv[1];
	if (!(lst_str_check(mini->env, str)))
		return ;
	while (ft_strncmp(str, mini->env->name, ft_strlen(str)))
	{
		temp = mini->env;
		mini->env = mini->env->next;
	}
	if(mini->env->next != NULL)
		temp2 = mini->env->next;
	else
		temp2 = NULL;
	temp->next = temp2;
	free(mini->env->next);
	mini->env->next = NULL;
	mini->env = head;
}
