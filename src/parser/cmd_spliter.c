/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_spliter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 02:51:20 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/19 01:28:08 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utilities.h"

// Bonus (split according to logic)
// && logic and
// || logic or
// (..) priority
static int	split(const char *str, t_commands *cmd, int j, int i)
{
	(void) str;
	(void) cmd;
	(void) j;
	(void) i;
	return (0);
}

t_tree	*split_cmd(char *c)
{
	t_tree *ret;

	(void)c;
	ret = NULL;
	return (ret);
}
/*
void	split_cmd(t_commands *cmd)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
		(str[i] & 0x80)
			|| ((str[i] == '&') && (str[i + 1] == '&')
				&& (j = split(str, cmd, j, i)))
			|| ((str[i] == '|') && (str[i + 1] == '|')
				&& (j = split(str, cmd, j, i)))
			|| ((str[i] == ';') && (j = split(str, cmd, j, i)))
			|| ((str[i] == '|') && (j = split(str, cmd, j, i)))
			|| ((str[i] == '(') && (j = split(str, cmd, j, i)));
	split_cmd2(str, cmd);
}



cmd1 && cmd2 | cmd3

*/
