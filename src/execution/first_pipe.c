/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:23:59 by fferreir          #+#    #+#             */
/*   Updated: 2021/11/25 18:51:55 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	fd_mng_builtins(t_cmd *cmd, int fd[2], int input, int output)
{
	close(fd[0]);
	if (cmd->in.in)
	{
		input = file_input(cmd->in.input);
		printf("INPUT = %d\n", input);
		if (input == -1)
			return (-1);
	}
	if (cmd->in.out)
	{
		output = file_output(cmd->in.output, cmd->in.append, cmd->in.out);
		printf("OUTPUT = %d\n", output);
	}
	else
	{
		if (dup2(fd[1], 1) == -1)
			printf("Error: Bad dup2 on first cmd pipe function");
	}
	screening_one(cmd->cmd);
	g_mini.saved_fd = fd[1];
	return (1);
}

static int	fd_mng_child_process(t_cmd *cmd, int fd[2], int input, int output)
{
	close(fd[0]);
	if (cmd->in.in)
	{
		input = file_input(cmd->in.input);
		if (input > 0)
			dup2(input, 0);
		else
			return (-1);
	}
	if (cmd->in.out)
	{
		output = file_output(cmd->in.output, cmd->in.append, cmd->in.out);
		if (output)
			dup2(output, 1);
	}
	else
	{
		if (dup2(fd[1], 1) == -1)
			printf("Error: Bad dup2 on first cmd pipe function");
	}
	cmd_selector(cmd->cmd);
	close(fd[1]);
	exit_fork();
	return (1);
}

int	first_cmd_pipe(t_cmd *cmd, int fd[2])
{
	int	pid;
	int	exit_status;
	int	output;
	int	input;

	exit_status = 0;
	input = 0;
	output = 0;
	pipe(fd);
	if (!cmd_identifier(cmd->cmd))
		return (fd_mng_builtins(cmd, fd, input, output));
	pid = fork();
	if (pid == 0)
		return (fd_mng_child_process(cmd, fd, input, output));
	else
	{
		close(fd[1]);
		exit_status = wait(0);
		g_mini.saved_fd = fd[0];
	}
	return (exit_status);
}
