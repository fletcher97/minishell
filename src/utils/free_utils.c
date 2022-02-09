/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:57:30 by mgueifao          #+#    #+#             */
/*   Updated: 2022/02/09 00:30:35 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	delete_temp(char *path)
{
	char	*file_path;
	char	*nbr;
	int		i;

	if (!path)
		return ;
	i = -1;
	while (++i < (g_mini.file_counter + 1))
	{
		nbr = ft_itoa(i);
		if (ft_strcmp(g_mini.hdoc_files[i], nbr) != 1)
		{
			file_path = ft_strjoin(path, g_mini.hdoc_files[i]);
			printf("%s\n ;;; counter = %d\n", file_path, g_mini.file_counter);
			unlink(file_path);
			free(file_path);
			free(g_mini.hdoc_files[i]);
			g_mini.hdoc_files[i] = ft_itoa(i);
		}
		free(nbr);
	}
}

//The free list node will receive a dual linked list and it will free up all its
//nodes. No malloc used on the nodes content will be freed.
void	free_list_nodes(t_dl_list *lst)
{
	t_dl_list	*temp;

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

//The free_argv function will free up all the variable on the arguments array
//created by the split function. Also free's up the table itself.
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

//The free dl list function will receive and destroy all nodes on a dual linked
//list. It will also free up the content on each node that so make sure all
//the content is set on the heap.
void	free_dl_list(t_dl_list *lst)
{
	t_dl_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst->content);
		free(lst->name);
		free(lst);
		lst = temp;
	}
}

/*
*   Frees up an array of strings that was malloced.
*/
void	free_table(char **array)
{
	int	i;

	i = -1;
	if (!array)
		return ;
	while (array[++i])
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}
