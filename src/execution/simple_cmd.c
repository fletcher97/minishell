/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:48:05 by fferreir          #+#    #+#             */
/*   Updated: 2021/12/21 19:11:51 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	fd_mng_builtins(t_cmd *cmd, int input, int output)
{
	if (cmd->in.in)
	{
		input = file_input(cmd->in.input, cmd->in.heredoc, cmd->in.in);
		if (input < 0)
			return (EXIT_FAILURE);
	}
	if (cmd->in.out)
	{
		output = file_output(cmd->in.output, cmd->in.append, cmd->in.out);
		if (output > 0)
			dup2(output, 1);
	}
	screening_one(cmd->cmd);
	if (output > 0)
		close(output);
	return (EXIT_SUCCESS);
}

static int	fd_mng_child_process(t_cmd *cmd, int input, int output)
{
	if (cmd->in.in)
	{
		input = file_input(cmd->in.input, cmd->in.heredoc, cmd->in.in);
		if (input > 0)
			dup2(input, 0);
		else
			return (EXIT_FAILURE);
	}
	if (cmd->in.out)
	{
		output = file_output(cmd->in.output, cmd->in.append, cmd->in.out);
		if (output > 0)
			dup2(output, 1);
		else
			return (EXIT_FAILURE);
	}
	cmd_selector(cmd->cmd);
	exit_fork();
	return (EXIT_FAILURE);
}

//The Simple Command function manages the command call of a single command call.
//Also, it manages the input and output file descriptors (FD).
int	simple_command(t_cmd *cmd)
{
	int	pid;
	int	input;
	int	output;
	int	status;

	if (g_mini.stop > 0)
		return (--g_mini.stop);
	input = 0;
	output = 0;
	if (!cmd_identifier(cmd->cmd))
		return (fd_mng_builtins(cmd, input, output));
	pid = fork();
	if (pid == 0)
	{
		fd_mng_child_process(cmd, input, output);
		return (EXIT_FAILURE);
	}
	if (waitpid(pid, &status, 0) == -1)
	{
		printf("waitpid failed");
		return (EXIT_FAILURE);
	}
	if (WIFEXITED(status))
		g_mini.exit_status = WEXITSTATUS(status);
	return (EXIT_SUCCESS);
}
