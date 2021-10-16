/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 03:47:09 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/16 05:21:20 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parser.h"
#include "ft_string.h"
#include "ft_ctype.h"

//TODO: replace return with define of error

static int	input(char *str, t_commands *cmd, int append)
{
	int	i;
	int	skip;

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
	if (!cmd->input)
		return (-1);
	cmd->input = ft_strncpy(cmd->input, str, i >> 2);
	cmd->input_flags = append;
	return (skip + (i >> 2));
}

static int	output(char *str, t_commands *cmd, int heredoc)
{
	int	i;
	int	skip;

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
	cmd->output = calloc(1, (i >> 2) + 1);
	if (!cmd->output)
		return (-1);
	cmd->output = ft_strncpy(cmd->output, str, i >> 2);
	cmd->output_flags = heredoc;
	return (skip + (i >> 2));
}

void	parse_op(const char *str, t_commands *cmd)
{
	char	q;
	char	*curr;
	int		i;

	q = 0;
	curr = (char *) str;
	while (*curr)
	{
		(*curr == '\'') && !(q & 2) && (q ^= 1);
		(*curr == '\"') && !(q & 1) && (q ^= 2);
		(q & 3) && curr++;
		if (q & 3)
			continue ;
		((ft_strncmp(curr, "<<", 2)) && ((i = input(curr + 1, cmd, 1)) || 1))
		|| ((ft_strncmp(curr, ">>", 3)) && ((i = output(curr, cmd, 1)) || 1))
		|| ((*curr == '<') && ((i = input(curr + 1, cmd, 0)) || 1))
		|| ((*curr == '>') && ((i = output(curr, cmd, 0)) || 1));
		if (i <= 0)
			cmd->error = i;
		if (i <= 0)
			return ;
		curr += i + 1;
	}
}
