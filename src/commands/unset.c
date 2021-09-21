/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:48:40 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/21 17:28:52 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	node_free_machine()
{
	free(mini.env->name);
	mini.env->name = NULL;
	mini.env = NULL;
}

// bool	str_len_check(char *s1, char *s2)
// {
// 	if ((ft_strlen(s1) - ft_strlen(s2)) == 0)
// 		return (true);
// 	return(false);
// }

// bool	str_cmp_both_len(char *s1, char *s2)
// {
// 	if (!str_len_check(s1, s2))
// 		return (false);
// 	if (!(ft_strncmp(s1,s2, ft_strlen(s1))))
// 	{
// 		if (!(ft_strncmp(s1,s2, ft_strlen(s2))))
// 			return (true);
// 	}
// 	return (false);
// }

bool	lst_str_check(t_list *lst, char *str)
{
	t_list	*head;
	char	*name;

	head = lst;
	while(1)
	{
		name = lst->name;
		if (ft_strcmp(name, str))
		{
				lst = head;
	//			printf("%s %s\n", str, name);
				return (true);
		}
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	lst = head;
	return (false);
}

void	ft_unset()
{
	t_list	*head;
	t_list	*temp;
	t_list	*temp2;

	head = mini.env;
	temp = NULL;
	if (!(lst_str_check(mini.env, mini.argv[1])))
		return ;
	while (!(ft_strcmp(mini.env->name, mini.argv[1])))
	{
		temp = mini.env;
		mini.env = mini.env->next;
	}
	if (mini.env->next != NULL)
		temp2 = mini.env->next;
	else
		temp2 = NULL;
	temp->next = temp2;
//	printf("N= |%s - %p|\n", mini.env->name, mini->env);
	node_free_machine();
	mini.env = head;
}
