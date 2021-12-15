/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:38:17 by fferreir          #+#    #+#             */
/*   Updated: 2021/12/09 16:11:43 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	file_input_instruction(t_cmd *cmd, int input)
{
	input = file_input(cmd->in.input, cmd->in.heredoc, cmd->in.in);
	if (input > 0)
	{
		dup2(input, 0);
		return (1);
	}
	else
		return (-1);
}

static int	fd_mng_builtins(t_cmd *cmd, int fd[2], int input, int output)
{
	if (cmd->in.in)
	{
		if (file_input_instruction(cmd, input) < 0)
			return (-1);
	}
	else
	{
		if (dup2(g_mini.saved_fd, 0) == -1)
			printf("Error: Bad dup2 on saved_fd to 0 pipe cmd function");
		close(g_mini.saved_fd);
	}
	if (cmd->in.out)
	{
		output = file_output(cmd->in.output, cmd->in.append, cmd->in.out);
		if (output > 0)
			dup2(output, 1);
	}
	else
	{
		if (dup2(fd[1], 1) == -1)
			printf("Error : bad dup2 on fd[1] to 1 on pipe cmd function\n");
	}
	screening_one(cmd->cmd);
	return (1);
}

static void	child_last_instructions(t_cmd *cmd, int fd[2])
{
	cmd_selector(cmd->cmd);
	close(fd[1]);
	close(fd[0]);
	exit_fork();
}

static int	fd_mng_child_process(t_cmd *cmd, int fd[2], int input, int output)
{
	if (cmd->in.in)
	{
		if (file_input_instruction(cmd, input) < 0)
			return (-1);
	}
	else
	{
		if (dup2(g_mini.saved_fd, 0) == -1)
			printf("Error: Bad dup2 on saved_fd to 0 pipe cmd child function");
		close(g_mini.saved_fd);
	}
	if (cmd->in.out)
	{
		output = file_output(cmd->in.output, cmd->in.append, cmd->in.out);
		if (output > 0 && dup2(output, 1) < 0)
			printf("Error : bad dup2 on output to 1 on pipe cmd function\n");
	}
	else
	{
		if (dup2(fd[1], 1) == -1)
			printf("Error : bad dup2 on fd[1] to 1 on pipe cmd function\n");
	}
	child_last_instructions(cmd, fd);
	return (1);
}

int	pipe_command(t_cmd *cmd, int fd[2])
{
	int	exit_status;
	int	pid;
	int	input;
	int	output;

	exit_status = 0;
	input = 0;
	output = 0;
	printf("CMD LINE = %s\n", cmd->line);
	pipe(fd);
	pid = fork();
	if (!cmd_identifier(cmd->cmd))
		return (fd_mng_builtins(cmd, fd, input, output));
	if (pid == 0)
		return (fd_mng_child_process(cmd, fd, input, output));
	else
	{
		close(fd[1]);
		exit_status = wait(0);
		printf("ES = %d for %s\n", exit_status, cmd->line);
		g_mini.saved_fd = fd[0];
	}
	return (exit_status);
}
