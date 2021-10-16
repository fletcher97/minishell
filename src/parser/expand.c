/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 06:20:05 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/16 10:49:21 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "ft_string.h"
#include "ft_ctype.h"
#include "ft_list.h"

#include "minishell.h"
#include "parser.h"

static char	*replace(char *s1, const char *s2, int pos, int len)
{
	char	*t1;
	char	*t2;

	t1 = ft_substr(s1, 0, pos);
	t2 = ft_strjoin(t1, s2);
	free(t1);
	t1 = ft_strjoin(t2, s1 + pos + len);
	free(t2);
	return (t1);
}

static int	expand1(char **s, int start)
{
	int		i;
	char	*str;
	char	*big;
	char	*var;

	i = start - 1;
	str = *s;
	while (ft_isalnum(str[++i]) || str[i] == '_')
		;
	i -= start;
	var = ft_substr(str, start, i);
	big = ft_listget_dl(var, g_mini.env);
	free(var);
	if (!big)
		return (0);
	*s = replace(str, big, start - 1, i + 1);
	i = ft_abs(i - ft_strlen(big));
	free(str);
	return (i);
}

char	*expand(char *s)
{
	int	i;

	i = -2;
	printf("--%s--\n", s);
	while (++i && s[(++i) >> 1])
	{
		(s[i >> 1] == '\'') && (i ^= 1);
		if (i & 1)
			continue ;
		if (s[i >> 1] == '$')
			i += (expand1(&s, (i >> 1) + 1) << 1);
	}
	return (s);
}
