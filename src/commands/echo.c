/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:15 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/09 18:00:53 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_no_flag(char **argv, int i, int j)
{
	if (i > 1)
	{
		j = 1;
		while (i > j)
			printf("%s ", argv[j++]);
		printf("\n");
	}
}

void	echo_n_flag(char **argv, int i, int j)
{
	if (i > 2)
	{
		j = 2;
		while (i > j)
		{
			printf("%s", argv[j]);
			if (i > 1 + j++)
				printf(" ");
		}
	}
}

void	ft_echo(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
		i++;
	if (i >= 2 && ft_strlen(argv[1]) > 0 && !ft_strncmp(argv[1], "-n",
			ft_strlen(argv[1])))
		echo_n_flag(argv, i, j);
	else
		echo_no_flag(argv, i, j);
}
