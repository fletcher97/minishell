/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:15 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/03 18:36:10 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *str)
{
	if (!ft_strncmp(str + 4, " ", 1))
	{
		if (!ft_strncmp(str + 5, "-n", 2))
		{
			if (!ft_strncmp(str + 4, " ", 1))
				printf("%s", str + 8);
			else
				return ;
		}
		else
			printf("%s\n", str + 5);
	}
	else
		printf("\n");
}
