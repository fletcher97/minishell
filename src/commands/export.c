/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:41:30 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/21 16:18:02 by falmeida         ###   ########.fr       */
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

bool	check_env_names(char *name, char *content)
{
	t_list	*head;

	head = mini.env;
	while(1)
	{
		if(str_cmp_both_len(name, mini.env->name))
		{
			//free(mini.env->content); Double free problems here
			mini.env->content = content;
			mini.env = head;
			return (true);
		}
		if (mini.env->next == NULL)
			break ;
		mini.env = mini.env->next;
	}
	mini.env = head;
	return(false);
}

int	ft_export()
{
	t_list	*head;
	t_list	*temp;
	char	*name;
	char	*content;
	char	*arg;

	head = mini.env;
	arg = mini.argv[1];
	name = get_name(arg, '=');
	if (!name)
		return(env_sorted(mini));
	//	return(sorted_env_list(mini, ft_lstsize(mini.env)));
	content = ft_substr(arg, find_char(arg,'=') + 1, ft_strlen(arg));
	if (!check_env_names(name, content))
	{
		temp = ft_lstnew(content);
		temp->name = name;
		ft_lstadd_back(&mini.env, temp);
	}
	mini.env = head;
	return(1);
}
