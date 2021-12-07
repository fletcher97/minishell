/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:51:31 by fferreir          #+#    #+#             */
/*   Updated: 2021/12/06 17:11:11 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	command_exec2(t_cmd *cmd)
{
	if (cmd->cmd_flags & 1)
		printf(" WILDE ");
	else if (cmd->cmd_flags & 2)
		printf(" EXITE ");
	else if (cmd->cmd_flags & 4)
		printf(" AND ");
	else if (cmd->cmd_flags & 8)
		printf(" OR ");
}

void	command_exec(t_cmd *cmd)
{
	if ((cmd->cmd_flags & 0x40) && g_mini.first_cmd)
		g_mini.exit_status = first_cmd_pipe(cmd, g_mini.fd);
	else if (cmd->cmd_flags & 0x40)
		g_mini.exit_status = pipe_command(cmd, g_mini.fd);
	else if ((cmd->cmd_flags & 0x10) && g_mini.first_cmd)
		g_mini.exit_status = simple_command(cmd);
	else if ((cmd->cmd_flags & 0x10) && !g_mini.first_cmd)
		g_mini.exit_status = end_multi_cmd(cmd, g_mini.fd);
	else if (cmd->cmd_flags & 0x20)
	{
		if (g_mini.first_cmd)
		{
			g_mini.exit_status = simple_command(cmd);
			g_mini.first_cmd = 1;
		}
		else
			g_mini.exit_status = end_multi_cmd(cmd, g_mini.fd);
	}
	else
		command_exec2(cmd);
	if (cmd->cmd_flags & 0x20)
		g_mini.first_cmd = 1;
	else
		g_mini.first_cmd = 0;
}
