/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:09:01 by fferreir          #+#    #+#             */
/*   Updated: 2022/01/12 18:47:38 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	hsi(int signal)
{
	rl_replace_line("", signal);
	printf("\nminishell: ");
}

//The Clean Processes function closes all possible open file descriptors and
//kill all open processes that were not naturally closed.

void clean_processes(void)
{
	int	i;

	i = 2;
	while (++i < MAX_FD)
		close(i);
	i = -1;
	while(g_mini.pid_lst[++i] > 0)
	{
		kill(g_mini.pid_lst[i], SIGTERM);
		g_mini.pid_lst[i] = -1;
	}
}

void	re_init(void)
{
	clean_processes();
	g_mini.fd_in = 0;
	g_mini.fd_out = 1;
	g_mini.cmd_counter = 0;
	g_mini.file_counter = 0;
	g_mini.hdoc_counter = 0;
	g_mini.and_flag = 0;
	g_mini.pid_counter = 0;
	g_mini.stop = 0;
}
