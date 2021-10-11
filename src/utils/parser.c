/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:57:37 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/11 19:19:41 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// after error_output
//		redirect_output(i, j);
//		redirect_input(i, j);
//		read_input_from(i, j);
//		append_output(i ,j);
//		error_output('s', i);
static int	resolve_special(int i, int j)
{
	if (j == 0)
		error_output('s', i);
	else if (j == 1)
		error_output('s', i);
	else if (j == 2)
		error_output('s', i);
	else if (j == 3)
		error_output('s', i);
	else if (j == 4 && i != 0)
		piper(i);
	else
		error_output('s', i);
	return (0);
}

int	find_special(void)
{
	char	**special;
	int		i;
	int		j;

	special = (char *[]){"<", ">", "<<", ">>", "|", ";", "&", "?", "*", "\\",
		"#", "$"};
	i = -1;
	while (g_mini.argv[++i])
	{
		j = -1;
		while (++j < 12 )
		{
			if (ft_strcmp(g_mini.argv[i], special[j]))
			{
				i = resolve_special(i, j);
				return (-1);
			}
		}
	}
	return (0);
}
