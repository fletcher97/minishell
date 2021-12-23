/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:51:31 by fferreir          #+#    #+#             */
/*   Updated: 2021/12/21 19:10:00 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	command_call2(t_cmd *cmd, int *fd)
{
	if (cmd->cmd_flags & 1)
		printf(" WILDE ");
	else if (cmd->cmd_flags & 2)
		printf(" EXITE ");
	else if (cmd->cmd_flags & 4)
	{
		if (g_mini.first_cmd)
			simple_command(cmd);
		else
			end_multi_cmd(cmd, fd);
		if (g_mini.exit_status != 0)
		{
			g_mini.stop++;
			g_mini.and_flag++;
		}
	}
	else if (cmd->cmd_flags & 8)
	{
		if (g_mini.first_cmd)
			simple_command(cmd);
		else
			end_multi_cmd(cmd, fd);
		if (g_mini.exit_status == 0)
			g_mini.stop++;
	}
}

static void	command_call(t_cmd *cmd)
{
	if ((cmd->cmd_flags & 0x40) && g_mini.first_cmd)
		first_cmd_pipe(cmd, g_mini.fd);
	else if (cmd->cmd_flags & 0x40)
		pipe_command(cmd, g_mini.fd);
	else if ((cmd->cmd_flags & 0x10) && g_mini.first_cmd)
		simple_command(cmd);
	else if ((cmd->cmd_flags & 0x10) && !g_mini.first_cmd)
		end_multi_cmd(cmd, g_mini.fd);
	else if (cmd->cmd_flags & 0x20)
	{
		if (g_mini.first_cmd)
		{
			simple_command(cmd);
			g_mini.first_cmd = 1;
		}
		else
			end_multi_cmd(cmd, g_mini.fd);
	}
	else
		command_call2(cmd, g_mini.fd);
}

//The Command_exec function will check the command flags and redirect it to the
//correct function. Also, it will manage the flag for 'first command' call as
//well as managing the stop flag for 'OR' commands.
void	command_exec(t_cmd *cmd)
{
	if (!cmd->cmd[0])
	{
		if ((cmd->cmd_flags & 8) && g_mini.exit_status == 0)
		{
			g_mini.stop = 1;
			g_mini.and_flag--;
		}
		if ((cmd->cmd_flags & 0x04) && g_mini.exit_status != 0)
			g_mini.stop = 1;
		g_mini.first_cmd = 1;
		return ;
	}
	command_call(cmd);
	if (cmd->cmd_flags & 0x04)
		g_mini.first_cmd = 1;
	else
		g_mini.first_cmd = 0;
}
