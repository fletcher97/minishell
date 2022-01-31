#include "execution.h"

static int	file_input_instruction(t_cmd *cmd, int input)
{
	input = file_input(cmd->in.input, cmd->in.heredoc, cmd->in.in);
	if (input > 0)
	{
		if (dup2(input, 0) != -1)
			return (EXIT_SUCCESS);
	}
	return (error_output('i', 0, ++cmd->in.input->content));
}

int	bultin_exec(t_cmd *cmd)
{
	int	output;
	int	input;

	input = 0;
	if (cmd->in.in)
	{
		if (file_input_instruction(cmd, input) < 0)
			return (EXIT_FAILURE);
	}
	if (cmd->in.out)
	{
		output = file_output(cmd->in.output, cmd->in.append, cmd->in.out);
		if (output < 0)
			dup2(output, 1);
	}
	screening_one(cmd->cmd);
	return (EXIT_SUCCESS);
}
