/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:00:39 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/09 14:11:09 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_output(t_mini *mini, char type)
{
	if (type == 'c')
		printf("minishell: command not found: %s\n", mini->argv[0]);
}

