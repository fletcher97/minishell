/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:48:05 by fferreir          #+#    #+#             */
/*   Updated: 2021/12/15 15:40:36 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	fd_mng_builtins(t_cmd *cmd, int input, int output)
{
	if (cmd->in.in)
	{
		input = file_input(cmd->in.input, cmd->in.heredoc, cmd->in.in);
		if (input < 0)
			return (-1);
	}
	if (cmd->in.out)
		output = file_output(cmd->in.output, cmd->in.append, cmd->in.out);
	screening_one(cmd->cmd);
	return (1);
}

static int	fd_mng_child_process(t_cmd *cmd, int input, int output)
{
	if (cmd->in.in)
	{
		input = file_input(cmd->in.input, cmd->in.heredoc, cmd->in.in);
		if (input > 0)
			dup2(input, 0);
		else
			return (-1);
	}
	if (cmd->in.out)
	{
		output = file_output(cmd->in.output, cmd->in.append, cmd->in.out);
		if (output > 0)
			dup2(output, 1);
		else
			return (-1);
	}
	cmd_selector(cmd->cmd);
	exit_fork();
	return (1);
}

int	simple_command(t_cmd *cmd)
{
	int	pid;
	int	exit_status;
	int	input;
	int	output;

	if (g_mini.stop)
		return (g_mini.exit_status);
	exit_status = 0;
	input = 0;
	output = 0;
	printf("CMD LINE S = %s\n", cmd->line);
	if (!cmd_identifier(cmd->cmd))
		return (fd_mng_builtins(cmd, input, output));
	pid = fork();
	if (pid == 0)
		return (fd_mng_child_process(cmd, input, output));
	else
		exit_status = wait(0);
	if (exit_status < 0)
		g_mini.stop = 1;
	printf("ES = %d for %s\n", exit_status, cmd->line);
	return (exit_status);
}
