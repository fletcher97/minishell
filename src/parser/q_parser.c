/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:03:59 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/24 08:04:04 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include "parser.h"
#include "utilities.h"

#include "stdlib.h"

static char	*rem_q(char *str, int count)
{
	char	*ret;
	int		p1;
	int		p2;

	ret = ft_calloc(ft_strlen(str) - count + 1, 1);
	p1 = -1;
	p2 = -1;
	while (str[++p1])
		if (!ft_strchr("\\\"\'", str[p1]))
			ret[++p2] = str[p1];
	ft_free(str);
	return (ret);
}

/**
 * q:
 *	S : single quotes
 *	D : double quotes
 *	Q : skip escape
 *	V : inside variable
 *
 * Toogle single quotes
 * Toogle double quotes
 * Escape next char
 * Enter var
 */
char	*proc_q(char *str, t_commands *cmd)
{
	char	q;
	int		count;
	char	*c;

	q = 0;
	count = 0;
	c = str - 1;
	while (*++c)
	{
		q &= ~Q;
		(*c == '\'') && !(q & D) && ((q ^= S | Q) || 1) && (count++);
		(*c == '\"') && !(q & S) && ((q ^= D | Q) || 1) && (count++);
		(*c == '$') && !(q & S) && (q |= V);
		(ft_strchr(" \'\"\\;&|", *c)) && (q &= ~V);
		(*c == '\\') && !(q & S) && (ft_strchr("$\\\"", *(c + 1))) &&
			(*(c++)) && (count++);
		(*c) && (q & (S | D)) && !(q & Q) && (*c |= 0x80);
	}
	if (q & (S | D))
		cmd->error = QUOTES_OPEN;
	return (rem_q(str, count));
}
