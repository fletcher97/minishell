/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:03:59 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/16 02:33:35 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error_mng.h"

# define CHAR_UNHANDLED 1
# define QUOTES_OPEN 2

void	proc_q(const char *str, t_commands *cmd)
{
	char		q1;
	char		q2;
	const char	*curr;

	q1 = 0;
	q2 = 0;
	curr = str;
	while(*curr)
	{
		if (*curr == '\'' && !q2)
			q1 = !q1;
		if (*curr == '\"' && !q1)
			q2 = !q2;
		curr++;
	}
	if (q1 || q2)
		cmd->error = QUOTES_OPEN;
}

void	split_cmd( const char *str, t_commands *cmd)
{
	char	q;

	q = 0;
	while (*str)
	{
		if (*str == '\"')
		{
			q = !q;
			str++;
			continue;
		}
		if (!q && *str == ';')
			cmd->error = CHAR_UNHANDLED;
		if (!q && *str == ';')
			return ;
		str++;
	}
}


t_commands	*parse(const char *str)
{
	t_commands	*cmd;

	cmd = calloc(1, sizeof(t_commands));
	proc_q(str, cmd);
	if (cmd->error)
		return (cmd);
	split_cmd(str, cmd);
	if (cmd->error)
		return (cmd);
	// parse_op(str, cmd);
	// expand(str, cmd);
	// word_splitting(str, cmd);
	return cmd;
}
