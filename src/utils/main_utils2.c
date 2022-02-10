/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 02:06:16 by fferreir          #+#    #+#             */
/*   Updated: 2022/02/10 10:56:16 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "ft_stdlib.h"
#include "ft_conv.h"

#include "utilities.h"
#include "minishell.h"

/*
*   It will be used to free the input variable and exit the fork. This function
*    is used when a command that tried to use the execve function fails to exe-
*    cute.
*/
void	exit_fork(void)
{
	ft_free(g_mini.input);
	exit(0);
}

/*
*   It will create and allocate and array with all the possible FDs so it can
*    later alocate the pathname of each created heredoc file.
*   It also created, allocate and initialize an array that will hold all the
*    all the future child pids.
*/
void	create_hdoc_and_pid_arrays(void)
{
	int	i;

	i = -1;
	g_mini.hdoc_files = ft_malloc(sizeof(char **) * (FD_MAX + 1));
	while (++i < FD_MAX)
		g_mini.hdoc_files[i] = ft_itoa(i);
	g_mini.hdoc_files[i] = NULL;
	g_mini.pid_lst = ft_malloc(sizeof(int *) * (CHILD_MAX + 1));
	i = -1;
	while (++i < CHILD_MAX)
		g_mini.pid_lst[i] = -1;
	g_mini.pid_lst[i] = '\0';
}

/*
*   It will call the function that will destroy the dual linked list that holds
*    the env list and will free all the variables on the global heredoc list.
*    It also frees the pid_list.
*/
void	exit_loop(void)
{
	int	i;

	free_dl_list(g_mini.env);
	i = -1;
	while (++i < FD_MAX)
		ft_free(g_mini.hdoc_files[i]);
	ft_free(g_mini.hdoc_files);
	ft_free(g_mini.pid_lst);
	exit(0);
}

/*
*   The Clean Processes function closes all possible open file descriptors and
*    kill all open processes that were not naturally closed.
*/
void	clean_processes(void)
{
	int	i;

	i = 2;
	while (++i < MAX_FD)
		close(i);
	i = -1;
	while (g_mini.pid_lst[++i] > 0)
	{
		kill(g_mini.pid_lst[i], SIGTERM);
		g_mini.pid_lst[i] = -1;
	}
}
