/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:51:31 by fferreir          #+#    #+#             */
/*   Updated: 2022/01/31 22:03:22 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	command_call(t_cmd *cmd)
{
	if (cmd->cmd_flags & 0x20)
	{
		if (g_mini.first_cmd)
			g_mini.first_cmd = 1;
	}
	else if (cmd->cmd_flags & 4)
	{
		if (g_mini.exit_status != 0)
		{
			g_mini.stop++;
			g_mini.and_flag++;
		}
	}
	else if (cmd->cmd_flags & 8)
	{
		if (g_mini.exit_status == 0)
		g_mini.stop++;
	}
	return (execute_cmd(cmd));
}

//The Command_exec function will check the command flags and redirect it to the
//correct function. Also, it will manage the flag for 'first command' call as
//well as managing the stop flag for 'OR' commands.
int	command_exec(t_cmd *cmd)
{
	int	ret;

	ret = 0;
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
		return (-2);
	}
	if (!cmd_identifier(cmd->cmd) && g_mini.first_cmd &&
			(cmd->cmd_flags & 0x10))
		return (bultin_exec(cmd));
	ret = command_call(cmd);
	if (cmd->cmd_flags & 0x04)
		g_mini.first_cmd = 1;
	else
		g_mini.first_cmd = 0;
	return (ret);
}
