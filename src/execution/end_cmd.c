/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:50:12 by fferreir          #+#    #+#             */
/*   Updated: 2021/12/07 15:15:14 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	fd_mng_builtins(t_cmd *cmd, int fd[2], int input, int output)
{
	close(fd[1]);
	close(fd[0]);
	if (cmd->in.in)
	{
		input = file_input(cmd->in.input, cmd->in.heredoc, cmd->in.in);
		if (input > 0)
			dup2(input, 0);
		else
			return (-1);
	}
	else if (g_mini.saved_fd > 0)
	{
		if (dup2(g_mini.saved_fd, 0) == -1)
			printf("Error: Bad dup2 on saved_fd to 0 end multi cmd function");
	}
	if (cmd->in.out)
	{
		output = file_output(cmd->in.output, cmd->in.append, cmd->in.out);
		if (output > 0)
			dup2(output, 1);
	}
	screening_one(cmd->cmd);
	close(g_mini.saved_fd);
	return (1);
}

static int	fd_mng_child_process(t_cmd *cmd, int fd[2], int input, int output)
{
	close(fd[1]);
	close(fd[0]);
	if (cmd->in.in)
	{
		input = file_input(cmd->in.input, cmd->in.heredoc, cmd->in.in);
		if (input > 0)
			dup2(input, 0);
		else
			return (-1);
	}
	else if (g_mini.saved_fd > 0)
	{
		if (dup2(g_mini.saved_fd, 0) == -1)
			printf("Error: Bad dup2 on s_fd to 0 end multi cmd child func\n");
	}
	if (cmd->in.out)
	{
		output = file_output(cmd->in.output, cmd->in.append, cmd->in.out);
		if (output > 0)
			dup2(output, 1);
	}
	cmd_selector(cmd->cmd);
	exit_fork();
	return (1);
}

int	end_multi_cmd(t_cmd *cmd, int fd[2])
{
	int	exit_status;
	int	pid;
	int	output;
	int	input;

	exit_status = 0;
	input = 0;
	output = 0;
	pipe(fd);
	pid = fork();
	if (!cmd_identifier(cmd->cmd))
		return (fd_mng_builtins(cmd, fd, input, output));
	if (pid == 0)
		exit_status = fd_mng_child_process(cmd, fd, input, output);
	else
	{
		close(fd[1]);
		close(fd[0]);
		exit_status = wait(0);
		close(g_mini.saved_fd);
		printf("EXIT END = %d\n", exit_status);
	}
	return (exit_status);
}
