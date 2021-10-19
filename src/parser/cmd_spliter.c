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
static void	split_cmd2(const char *str, t_commands *cmd)
{
	(void) str;
	(void) cmd;
}

static int	split(const char *str, t_commands *cmd, int j, int i)
{
	(void) str;
	(void) cmd;
	(void) j;
	(void) i;
	return (0);
}

void	split_cmd(const char *str, t_commands *cmd)
{
	char	q;
	int		i;
	int		j;

	q = 0;
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '\"')
			q = !q;
		if (str[i] == '\"')
			continue ;
		if (!q && *str == ';')
			cmd->error = CHAR_UNHANDLED;
		if (!q && *str == ';')
			return ;
		if (!q && *str == '|')
			j = split(str, cmd, j, i);
	}
	split_cmd2(str, cmd);
}
/*

cmd1 && cmd2 | cmd3

*/
