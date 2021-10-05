/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:57:22 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/05 22:57:25 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_output(char type, int i)
{
	if (i < 0)
		i = 0;
	if (type == 'c')
		printf("minishell: command not found: %s\n", g_mini.argv[i]);
	if (type == 's')
		printf("minishell: special character not define: %s\n", g_mini.argv[i]);
}
