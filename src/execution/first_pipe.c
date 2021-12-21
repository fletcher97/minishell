/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:23:59 by fferreir          #+#    #+#             */
/*   Updated: 2021/12/21 19:45:51 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	fd_mng_builtins(t_cmd *cmd, int fd[2], int input, int output)
{
	close(fd[0]);
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
	else
	{
		if (dup2(fd[1], 1) == -1)
			printf("Error: Bad dup2 on first cmd pipe function");
	}
	screening_one(cmd->cmd);
	if (output > 0)
		g_mini.saved_fd = output;
	else
		g_mini.saved_fd = fd[1];
	return (EXIT_SUCCESS);
}

static int	fd_mng_child_process(t_cmd *cmd, int fd[2], int input, int output)
{
	close(fd[0]);
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
	}
	else
	{
		if (dup2(fd[1], 1) == -1)
			printf("Error: Bad dup2 on first cmd pipe function");
	}
	cmd_selector(cmd->cmd);
	close(fd[1]);
	exit_fork();
	return (EXIT_FAILURE);
}

static int	fd_mng_parent_process(int fd[2], int pid)
{
	int	status;

	close(fd[1]);
	if (waitpid(pid, &status, 0) == -1)
	{
		printf("waitpid failed");
		return (EXIT_FAILURE);
	}
	if (WIFEXITED(status))
		g_mini.exit_status = WEXITSTATUS(status);
	g_mini.saved_fd = fd[0];
	return (EXIT_SUCCESS);
}

//The First Cmd Pipe function will check for the pipe flag for the first cmd on
//at least a pipe. It will also manage the 'first_cmd' flag. Also, it manages
//the input and output file descriptors (FD's).
int	first_cmd_pipe(t_cmd *cmd, int fd[2])
{
	int	pid;
	int	output;
	int	input;

	input = 0;
	output = 0;
	pipe(fd);
	if (!cmd_identifier(cmd->cmd))
		return (fd_mng_builtins(cmd, fd, input, output));
	pid = fork();
	if (pid == 0)
	{
		fd_mng_child_process(cmd, fd, input, output);
		return (EXIT_FAILURE);
	}
	else
	{
		if (fd_mng_parent_process(fd, pid) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
