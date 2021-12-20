/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:42:21 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/20 18:51:05 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_string.h"

static void	find_bound(int *start, int *end, char *s, int i){
	(void)end;
	(void)s;
	(void)i;
	*start = -1;

}

int	wild(int i, char *s, t_cmd *cmd){
	int		start;
	int		end;
	char	*wild;

	find_bound(&start, &end, s, i);
	if (start == -1)
		cmd->cmd_flags |= 1;
	if (start == -1)
		return (i);
	wild = ft_substr(s, start, end);

	return (i);
}
