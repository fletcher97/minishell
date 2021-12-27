/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:50:12 by fferreir          #+#    #+#             */
/*   Updated: 2021/12/27 17:20:28 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	fd_mng_builtins(t_cmd *cmd, int fd[2], int input)
{
	close(fd[1]);
	close(fd[0]);
	if (cmd->in.in)
	{
		input = file_input(cmd->in.input, cmd->in.heredoc, cmd->in.in);
		if (input > 0 && dup2(input, 0) < 0)
			return (error_output('i', 0, ++cmd->in.input->content));
	}
	else if (g_mini.saved_fd > 0)
		dup2(g_mini.saved_fd, 0);
	if (cmd->in.out)
		file_output(cmd->in.output, cmd->in.append, cmd->in.out);
	screening_one(cmd->cmd);
	close(g_mini.saved_fd);
	return (EXIT_SUCCESS);
}

static int	fd_mng_child_process(t_cmd *cmd, int fd[2], int input, int output)
{
	close(fd[1]);
	close(fd[0]);
	if (cmd->in.in)
	{
		input = file_input(cmd->in.input, cmd->in.heredoc, cmd->in.in);
		if (input > 0 && dup2(input, 0) < 0)
			return (error_output('i', 0, ++cmd->in.input->content));
	}
	else if (g_mini.saved_fd > 0)
		dup2(g_mini.saved_fd, 0);
	if (cmd->in.out)
	{
		output = file_output(cmd->in.output, cmd->in.append, cmd->in.out);
		if (output > 0)
			dup2(output, 1);
	}
	cmd_selector(cmd->cmd);
	exit_fork();
	return (EXIT_FAILURE);
}

static int	fd_mng_parent_process(int fd[2], int pid)
{
	int	status;

	close(fd[1]);
	close(fd[0]);
	if (waitpid(pid, &status, 0) == -1)
	{
		printf("waitpid failed");
		return (EXIT_FAILURE);
	}
	if (WIFEXITED(status))
		g_mini.exit_status = WEXITSTATUS(status);
	close(g_mini.saved_fd);
	return (EXIT_SUCCESS);
}

//The End Multi Cmd function manage the 'END' flag from a multi command call
//with, at least, one pipe on the command line.
//Also, it manages the input and output file descriptors (FD's).
int	end_multi_cmd(t_cmd *cmd, int fd[2])
{
	int	pid;
	int	output;
	int	input;

	if (g_mini.stop)
		return (--g_mini.stop);
	input = 0;
	output = 0;
	pipe(fd);
	pid = fork();
	if (!cmd_identifier(cmd->cmd))
		return (fd_mng_builtins(cmd, fd, input));
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
