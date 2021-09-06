/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:15 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/06 17:32:37 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **argv)
{
	int	i;

	i = 0;

	if (ft_strlen(argv[1]) > 0 && !ft_strncmp(argv[1], "-n", ft_strlen(argv[1])))
	{
		if (argv[2])
		{
			i = 2;
			while (argv[i + 1] != NULL)
			{
				printf("%s ", argv[i]);
				i++;
			}
			printf("%s", argv[i]);
		}
		else
			return ;
	}
	else
	{
		if (ft_strlen(argv[1]) > 0)
		{
			i = 1;
			while (argv[i + 1] != NULL)
			{
				printf("%s ", argv[i]);
				i++;
			}
			printf("%s\n", argv[i]);
		}
		else
			printf("\n");
	}
}
