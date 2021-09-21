/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:32:09 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/21 16:13:38 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_dp_list(t_list *lst)
{
	t_list *temp;

	if (!lst)
		return ;
	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = NULL;
		lst = temp;
	}
}

void	free_argv()
{
	int x;
	int y;

	x = 0;
	while (mini.argv[x] != NULL)
		x++;
	y = -1;
	while (++y < x)
	{
		free(mini.argv[y]);
		mini.argv[y] = NULL;
	}
	free(mini.argv);
}

void	free_lst(t_list *lst)
{
	if (lst == NULL)
	{
		free(lst);
		lst = NULL;
		return ;
	}
	while(1)
	{
		printf("%s %p\n",lst->content,lst->content);
		free(lst->content);
		lst->content = NULL;
		free(lst->name);
		lst->name = NULL;
		if (lst->next == NULL)
		{
			free(lst);
			lst = NULL;
			break ;
		}
		lst = lst->next;
	}
}

void	free_struct(char *input)
{
	free(mini.env);
	mini.env = NULL;
//	free(input);
	input = NULL;
//	free_argv(mini);
}
