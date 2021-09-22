/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:00:39 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/22 12:26:38 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_output(char type, int i)
{
	if (i < 0)
		i = 0;
	if (type == 'c')
		printf("minishell: command not found: %s\n", mini.argv[i]);
	if (type == 's')
		printf("minishell: special character not define: %s\n", mini.argv[i]);
}

