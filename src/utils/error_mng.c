/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:00:39 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/21 16:19:43 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_output(char type)
{
	if (type == 'c')
		printf("minishell: command not found: %s\n", mini.argv[0]);
}

