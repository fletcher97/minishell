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

#include "ft_string.h"

#include "parser.h"
#include "utilities.h"

static char	*proc_q(char *str, t_commands *cmd)
{
	char		q;

	q = 0;
	while (*str)
	{
		q |= 4;
		(*str == '\'') && !(q & 2) && (q ^= 5);
		(*str == '\"') && !(q & 1) && (q ^= 6);
		(q & 4) && (str &= )
		str++;
	}
	if (q1 || q2)
		cmd->error = QUOTES_OPEN;
	return (str);
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

	cmd = calloc(1, sizeof(t_commands));
	cmd->line = proc_q(ft_strdup(str), cmd);
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
