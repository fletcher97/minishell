/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:57:30 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/05 22:57:32 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_dp_list(t_list *lst)
{
	t_list	*temp;

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

void	free_argv(void)
{
	int	x;
	int	y;

	x = 0;
	while (g_mini.argv[x] != NULL)
		x++;
	y = -1;
	while (++y < x)
	{
		free(g_mini.argv[y]);
		g_mini.argv[y] = NULL;
	}
	free(g_mini.argv);
}

void	free_lst(t_list *lst)
{
	if (lst == NULL)
	{
		free(lst);
		lst = NULL;
		return ;
	}
	while (1)
	{
		printf("%s %p\n", (char *)lst->content, lst->content);
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

//	free(input);
//	free_argv(g_mini);
void	free_struct(char *input)
{
	free(g_mini.env);
	g_mini.env = NULL;
	input = NULL;
}
