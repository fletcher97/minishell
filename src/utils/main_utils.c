/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:09:01 by fferreir          #+#    #+#             */
/*   Updated: 2022/02/09 00:12:07 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	hsi(int signal)
{
	rl_replace_line("", signal);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
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
	g_mini.first_cmd = 1;
	g_mini.stop = 0;
	g_mini.and_flag = 0;
	g_mini.or_flag = 0;
	g_mini.es_flag = 0;
}

/*
*   Modifies the STOP, AND, OR and ES flags if the command flag && or || was
*    flagged.
*/
static void	and_or_flag(t_cmd *cmd)
{
	if ((cmd->cmd_flags & 0x04))
	{
		if (g_mini.exit_status != 0)
		{
			g_mini.es_flag = g_mini.exit_status;
			g_mini.and_flag++;
			g_mini.stop = 1;
		}
		else
			g_mini.and_flag++;
	}
	else
		g_mini.and_flag = 1;
	if (cmd->cmd_flags & 0x08)
	{
		if (!g_mini.exit_status)
		{
			g_mini.es_flag = g_mini.exit_status;
			g_mini.or_flag++;
			g_mini.stop = 2;
		}
		else
			g_mini.or_flag++;
	}
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
	if (cmd && !(cmd->cmd_flags & 0x40))
	{
		if (cmd->cmd[0])
		{
			and_or_flag(cmd);
			if (cmd->cmd_flags & 0x10)
			{
				if (g_mini.and_flag > 0 && (g_mini.es_flag || g_mini.exit_status))
				{
					if (g_mini.exit_status)
						g_mini.stop = 3;
				}
				else if (g_mini.or_flag > 0 && (!g_mini.es_flag || !g_mini.exit_status))
				{
					if (g_mini.exit_status)
						g_mini.stop = 4;
					else
						g_mini.stop = -2;
				}
			}
			else if ((cmd->cmd_flags & 0x20))
				g_mini.stop = -10;
		}
		tree_loop(t, i);
	}
}
