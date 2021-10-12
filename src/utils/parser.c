/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:57:37 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/12 17:37:45 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//The resolve special function is just a sorter. It will redirect the input to
//the right function, depending on the integer it received.
//Each integer corresponds to an special character like pipe, redirect, etc.
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

//The find special function will search for special characters on a string.
//It receives a table with arguments (argv) and look for them in each argument.
//If a special char is found, it will order it to be executed and then return
//the value '-1' (minus one). It returns '0' (zero) otherwise.
//This value will be used by the main function sorter.
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
