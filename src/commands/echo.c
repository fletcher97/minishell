/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:15 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/03 20:55:11 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **argv)
{
	if (argv[1])
	{
		if (!ft_strncmp(argv[1], "-n", 2))
		{
			if (argv[2])
				printf("%s", argv[2]);
			else
				return ;
		}
		else
			printf("%s\n", argv[1]);
	}
	else
		printf("\n");
}