/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:57:22 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/12 16:55:58 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_mng.h"

//Error output function is used to output an error msg based on the error type
//it received.
void	error_output(char type, int i)
{
	if (i < 0)
		i = 0;
	if (type == 'c')
		printf("minishell: command not found: %s\n", g_mini.argv[i]);
	if (type == 's')
		printf("minishell: special character not define: %s\n", g_mini.argv[i]);
}
