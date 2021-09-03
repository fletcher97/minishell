/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:15 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/03 20:25:43 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_mini *mini)
{

	if (!ft_strncmp(mini->argv[0], "echo", 4))
	{
		if (mini->argv[1])
		{
			if (!ft_strncmp(mini->argv[1], "-n", 2))
			{
				if (mini->argv[2])
					printf("%s", mini->argv[2]);
				else
					return ;
			}
			else
				printf("%s\n", mini->argv[1]);
		}
	}
	else
		return ;
}
