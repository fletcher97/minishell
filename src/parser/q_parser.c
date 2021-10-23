/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_parser.c                                         :+:      :+:    :+:   */
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

#include <stdlib.h>

static char	*rem_q(char *str, int count)
{
	char *ret;
	int p1;
	int p2;

	ret = malloc(ft_strlen(str) - count + 1);
	p1 = -1;
	p2 = -1;
	while (str[++p1])
		if (!ft_strchr("\\\"\'", str[p1]))
			ret[++p2] = str[p1];
	free(str);
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
# define S 1
# define D 2
# define Q 4
# define V 8
char	*proc_q(char *str, t_commands *cmd)
{
	(void)cmd;
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
		(*c == '\\') && !(q & S) && (*(c++)) && (count++);
		(*c) && (q & (S | D)) && !(q &  bQ) && (*c |= 0x80);
	}
//	if (q1 || q2)
//		cmd->error = QUOTES_OPEN;
	return (rem_q(str, count));
}
