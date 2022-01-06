#include <execution.h>

static void	file_output_instruction(t_cmd *cmd)
{
	g_mini.fd_out = file_output(cmd->in.output, cmd->in.append, cmd->in.out);
	if (g_mini.fd_out < 0)
		printf("NO OUTPUT FILE ERROR TO ADD\n");
	else if (g_mini.fd_out == 1)
		g_mini.fd_out = dup(g_mini.tmp_out);
	if (g_mini.fd_out < 0)
		printf("PREVIOUS OUTPUT ERROR\n");
}

static int	file_input_instruction(t_cmd *cmd)
{
	g_mini.fd_in = file_input(cmd->in.input, cmd->in.heredoc, cmd->in.in);
	if (g_mini.fd_in < 0)
	{
		dup2(g_mini.tmp_in, 0);
		dup2(g_mini.tmp_out, 1);
		close(g_mini.tmp_in);
		close(g_mini.tmp_out);
		return (0);
	}
	if (dup2(g_mini.fd_in, 0) < 0)
		close(g_mini.fd_in);
	return (1);
}

void	check_pipe(t_cmd *cmd)
{
	if (cmd->cmd_flags & 0x40)
	{
		pipe(g_mini.fd);
		g_mini.fd_in = g_mini.fd[0];
		g_mini.fd_out = g_mini.fd[1];
	}
	dup2(g_mini.fd_out, 1);
	close(g_mini.fd_out);
}

int	execute_cmd(t_cmd *cmd)
{
	file_output_instruction(cmd);
	if (!file_input_instruction(cmd))
		return (error_output('i', 0, ++cmd->in.input->content));
	if (g_mini.fd_out < 0)
		return (-1);
	check_pipe(cmd);
	g_mini.pid[g_mini.pid_counter++] = fork();
	if (g_mini.pid[g_mini.pid_counter] == 0)
		cmd_selector(cmd->cmd);
	return (1);
}
