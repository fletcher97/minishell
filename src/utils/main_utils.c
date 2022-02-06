/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:09:01 by fferreir          #+#    #+#             */
/*   Updated: 2022/02/06 23:45:49 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	hsi(int signal)
{
	rl_replace_line("", signal);
	printf("\nminishell: ");
}

/*
*   The Clean Processes function closes all possible open file descriptors and
*    kill all open processes that were not naturally closed.
*/
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

/*
*   It will re-initialize all the variables that are needed to be reseted for
*    the input loop. It will also call the Clean Processes function.
*/
void	re_init(void)
{
	clean_processes();
	g_mini.fd_in = 0;
	g_mini.fd_out = 1;
	g_mini.cmd_counter = 0;
	g_mini.file_counter = 0;
	g_mini.hdoc_counter = 0;
	g_mini.pid_counter = -1;
	g_mini.stop = 0;
	g_mini.first_cmd = 1;
}

/*
*   It checks the AND and OR flag in case there is a command so it can call the
*    tree_loop function and so it can execute the next command. This is necessa-
*    ry because the commands work inside a while loop that is forked and we
*    we only have access to the Exit Status of the command after it resolves.
*   It will also modifies the STOP variable at this stage so that the next
*    command will not resolve in case the STOP is > 0.
*/
void check_and_or_flag(t_cmd *cmd, t_tree *t, int i)
{
	if (cmd && (cmd->cmd_flags & 0x04 || cmd->cmd_flags & 0x08))
	{
		if ((cmd->cmd_flags & 0x08) && g_mini.exit_status == 0)
			g_mini.stop++;
		if ((cmd->cmd_flags & 0x04) && g_mini.exit_status != 0)
			g_mini.stop++;
		if ((cmd->cmd_flags & 0x20))
			g_mini.stop = 0;
		tree_loop(t, i);
	}
}
