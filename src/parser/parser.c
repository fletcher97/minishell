/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:03:59 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/16 20:22:50 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utilities.h"

static void	proc_q(const char *str, t_commands *cmd)
{
	char		q1;
	char		q2;

	q1 = 0;
	q2 = 0;
	while (*str)
	{
		if (*str == '\'' && !q2)
			q1 = !q1;
		if (*str == '\"' && !q1)
			q2 = !q2;
		str++;
	}
	if (q1 || q2)
		cmd->error = QUOTES_OPEN;
}

void	free_cmd(t_commands *cmd)
{
	int	i;

	if (cmd->cmd)
		free(cmd->cmd);
	i = -1;
	if (cmd->line)
		free(cmd->line);
	if (cmd->args)
		while (cmd->args[++i])
			free(cmd->args[i]);
	if (cmd->args)
		free(cmd->args);
	if (cmd->input)
		free(cmd->input);
	if (cmd->output)
		free(cmd->output);
}

t_commands	*parse(const char *str)
{
	t_commands	*cmd;
	t_commands	*tmp;

	cmd = calloc(1, sizeof(t_commands));
	proc_q(str, cmd);
	if (cmd->error)
		return (cmd);
	split_cmd(str, cmd);
	if (cmd->error)
		return (cmd);
	tmp = cmd;
	while (tmp)
	{
		parse_op(str, cmd);
		tmp->line = expand(cmd->line, cmd);
		tmp->output = expand(cmd->output, cmd);
		tmp->input = expand(cmd->input, cmd);
		if (cmd->error)
			return (cmd);
		tmp = tmp->next;
	}
	return (cmd);
}
// Missing
// word_splitting(str, cmd);
