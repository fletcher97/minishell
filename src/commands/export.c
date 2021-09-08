/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:41:30 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/08 14:44:17 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_cpy_after_char(char *s1, char c)
{
	char	*s2;
	int		x;
	int		y;

	x = 0;
	s2 = NULL;
	while (s1[x] && s1[x] != c)
		x++;
	x++;
	y = 0;
	while(s1[x])
	{
		s2[y] = s1[x + y];
		y++;
	}
	return (s2);
}

bool	check_env_names(t_mini *mini, char *name)
{
	while(1)
	{
	//	printf("%s %s\n", name, mini->env->name);
		if(!(ft_strncmp(name, mini->env->name, ft_strlen(mini->env->name))))
		{
	//		printf("%s %s\n", name, mini->env->name);
			mini->env->content = ft_cpy_after_char(mini->argv[1], '=');
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
	char *name;

	head = mini->env;
	name = get_name(mini->argv[1], '=');
//	printf("%s %s\n", name, mini->env->name);
	if (!check_env_names(mini, name))
	{
		temp = ft_lstnew(mini->argv[1]);
		temp->name = name;
		ft_lstadd_back(&mini->env, temp);
	}
	mini->env = head;
}
