/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:57:22 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/21 14:48:56 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

//Error output function is used to output an error msg based on the error type
//it received.
void	error_output(char type, int i)
{
	if (i < 0)
		i = 0;
	if (type == 'c')
	{
		printf("minishell: command not found: %s\n", g_mini.argv[i]);
		g_mini.exit_status = 127;
	}
	if (type == 's')
	{
		printf("minishell: special character not defined: %s\n", g_mini.argv[i]);
		g_mini.exit_status = 33;
	}
}
