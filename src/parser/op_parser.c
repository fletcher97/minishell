/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 03:47:09 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/16 10:42:17 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "parser.h"
#include "ft_string.h"
#include "ft_ctype.h"

//TODO: replace return with define of error

static int	input(char *str, t_commands *cmd, int append)
{
	int	i;
	int	skip;

//	if (cmd->input)
//		return (-2);
	skip = 0;
	while (ft_isspace((int)*str) && ++skip)
		str++;
	i = 0;
	while (str[i >> 2] && ((i & 3) || !ft_isspace(str[i >> 2])))
	{
		if (str[i >> 2] == '\'' && !(i & 2))
			i ^= 1;
		if (str[i >> 2] == '\"' && !(i & 1))
			i ^= 2;
		i += 4;
	}
	cmd->input = calloc(1, (i >> 2) + 1);
//	if (!cmd->input)
//		return (-1);
//	cmd->input = ft_strncpy(cmd->input, str, i >> 2);
//	cmd->input_flags = !!append;
	return (skip + (i >> 2) + !!append);
}

static int	output(char *str, t_commands *cmd, int heredoc)
{
	int	i;
	int	skip;

//	if (cmd->output)
//		return (-2);
	skip = 0;
	while (*str && ft_isspace((int)*str) && ++skip)
		str++;
	i = 0;
	while (str[i >> 2] && ((i & 3) || !ft_isspace(str[i >> 2])))
	{
		if (str[i >> 2] == '\'' && !(i & 2))
			i ^= 1;
		if (str[i >> 2] == '\"' && !(i & 1))
			i ^= 2;
		i += 4;
	}
//	cmd->output = calloc(1, (i >> 2) + 1);
//	if (!cmd->output)
//		return (-1);
//	cmd->output = ft_strncpy(cmd->output, str, i >> 2);
//	cmd->output_flags = !!heredoc;
	return (skip + (i >> 2) + !!heredoc);
}

void	parse_op(const char *str, t_commands *cmd)
{
	char	q;
	char	*cur;
	int		i;

	q = 0;
	cur = (char *) str;
	while (*cur)
	{
		(*cur == '\'') && !(q & 2) && (q ^= 1);
		(*cur == '\"') && !(q & 1) && (q ^= 2);
		(q & 3) && cur++;
		if (q & 3)
			continue ;
		((!ft_strncmp(cur, "<<", 2)) && ((i = input(cur + 2, cmd, 1)) || 1))
		|| ((!ft_strncmp(cur, ">>", 2)) && ((i = output(cur + 2, cmd, 1)) || 1))
		|| ((*cur == '<') && ((i = input(cur + 1, cmd, 0)) || 1))
		|| ((*cur == '>') && ((i = output(cur + 1, cmd, 0)) || 1))
		|| (i = 0);
		if (i < 0)
			cmd->error = i;
		if (i < 0)
			return ;
		cur += i + 1;
	}
}
