/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:51:31 by fferreir          #+#    #+#             */
/*   Updated: 2022/02/10 10:43:43 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "execution.h"
#include "minishell.h"

/*
*   The Command_exec function will check the command flags and redirect it to
*    the correct function. Also, it will manage the flag for 'first command'
*    call.
*   Built in commands calls that will modify internal variable that are request
*    with a simple command (no pipes) will also be checked and run outside
*    without a child.
*   Flags used:
*    If (cmd_flags & 0x40) input piped to next command.
*/
int	command_exec(t_cmd *cmd)
{
	int	ret;

	ret = 0;
	if (!cmd_identifier(cmd->cmd) && g_mini.first_cmd
		&& !(cmd->cmd_flags & 0x40))
		return (builtin_exec(cmd));
	ret = execute_cmd(cmd);
	if (cmd->cmd_flags & 0x40)
		g_mini.first_cmd = 0;
	else
		g_mini.first_cmd = 1;
	return (ret);
}
