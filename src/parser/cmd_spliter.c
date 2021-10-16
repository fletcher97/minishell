/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_spliter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 02:51:20 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/16 04:50:02 by mgueifao         ###   ########.fr       */
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

void	split_cmd(const char *str, t_commands *cmd)
{
	char	q;

	q = 0;
	while (*str)
	{
		if (*str == '\"')
		{
			q = !q;
			str++;
			continue ;
		}
		if (!q && *str == ';')
			cmd->error = CHAR_UNHANDLED;
		if (!q && *str == ';')
			return ;
		str++;
	}
	split_cmd2(str, cmd);
}
