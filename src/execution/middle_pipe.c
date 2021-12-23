/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:38:17 by fferreir          #+#    #+#             */
/*   Updated: 2021/12/17 16:23:15 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	file_input_instruction(t_cmd *cmd, int input)
{
	input = file_input(cmd->in.input, cmd->in.heredoc, cmd->in.in);
	if (input > 0)
	{
		if (dup2(input, 0))
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

static int	fd_mng_builtins(t_cmd *cmd, int fd[2], int input, int output)
{
	if (cmd->in.in)
	{
		if (file_input_instruction(cmd, input) < 0)
			return (EXIT_FAILURE);
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
	return (EXIT_SUCCESS);
}

static int	fd_mng_child_process(t_cmd *cmd, int fd[2], int input, int output)
{
	if (cmd->in.in)
	{
		if (file_input_instruction(cmd, input) < 0)
			return (EXIT_FAILURE);
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
	cmd_selector(cmd->cmd);
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

//The Pipe command function manages the pipe flag (indicates there are more pipe
//call after this).
//Also, it manages the input and output file descriptors (FD's).
int	pipe_command(t_cmd *cmd, int fd[2])
{
	int	pid;
	int	input;
	int	output;

	input = 0;
	output = 0;
	pipe(fd);
	pid = fork();
	if (!cmd_identifier(cmd->cmd))
		return (fd_mng_builtins(cmd, fd, input, output));
	if (pid == 0)
	{
		fd_mng_child_process(cmd, fd, input, output);
		close(fd[1]);
		close(fd[0]);
		exit_fork();
		return (EXIT_FAILURE);
	}
	else
	{
		if (fd_mng_parent_process(fd, pid) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
