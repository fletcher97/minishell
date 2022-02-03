/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:51:31 by fferreir          #+#    #+#             */
/*   Updated: 2022/02/03 22:35:24 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

/*
*   Checks for the END (;) flag so it can reset the First_cmd variable;
*   Also, it modifies the STOP variable in case it detects the OR flag;
*   Also, stops the cmd to be executed in case STOP variable is > 0.
*/
static int	stop_check(t_cmd *cmd)
{
	if (g_mini.stop > 0)
		return (g_mini.exit_status);
	return (execute_cmd(cmd));
}

/*
*   The Command_exec function will check the command flags and redirect it to the
*   correct function. Also, it will manage the flag for 'first command' call as
*   well as managing the stop flag for 'OR' commands.
*   Flags used:
*   If (cmd_flags & 0x01) at least one argument/cmd has a possible wildcard.
*   If (cmd_flags & 0x02) at least one argument/cmd needs to expand exit code.
*   If (cmd_flags & 0x04) cmd is to be executed before a &&
*   If (cmd_flags & 0x08) cmd is to be executed before a ||
*   If (cmd_flags & 0x10) cmd is at the end of a list
*   If (cmd_flags & 0x20) cmd is to be executed before a ; therefore reseting
*     logic.
*   If (cmd_flags & 0x40) input piped to next command
*/
int	command_exec(t_cmd *cmd)
{
	int	ret;

	ret = 0;
	if (!cmd->cmd[0])
	{
		if ((cmd->cmd_flags & 0x08) && g_mini.exit_status == 0)
			g_mini.stop--;
		if ((cmd->cmd_flags & 0x04) && g_mini.exit_status != 0)
			g_mini.stop++;
		g_mini.first_cmd = 1;
		return (-2);
	}
	if (!cmd_identifier(cmd->cmd) && g_mini.first_cmd &&
			((cmd->cmd_flags & 0x10) || (cmd->cmd_flags & 0x20)))
		return (bultin_exec(cmd));
	ret = stop_check(cmd);
	if (cmd->cmd_flags & 0x40)
		g_mini.first_cmd = 0;
	else
		g_mini.first_cmd = 1;
	return (ret);
}
