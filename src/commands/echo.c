/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:05 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/17 16:46:01 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

//The Env Flag Check function will check for the requested env on out internal
//and it will return its name.
// static char	*env_flag_check(char **argv, int i)
// {
// 	char	*env_name;
// 	int		j;

// 	j = 0;
// 	env_name = NULL;
// 	while (argv[i][j])
// 		j++;
// 	if (j > 0 && argv[i][0] == '$')
// 	{
// 		env_name = ft_substr(argv[i], 1, j);
// 		return (env_name);
// 	}
// 	return (NULL);
// }

//The Echo Flag function checks for the env varible flag ($) and the exit status
//($?). It will return its content if it finds it on the program internal list.
static void	echo_flag(char **argv, int i, int j, int k)
{
	if (i > k)
	{
		j = k;
		while (i > j)
		{
			if (ft_strcmp(argv[j], "$?"))
				printf("%d", g_mini.errno);
			else
				printf("%s", argv[j]);
			if (i > 1 + j++)
				printf(" ");
		}
		if (k == 1)
			printf("\n");
	}
}

//The Echo command function is used to print the inputed arguments provided.
//It will check for the '-n' flag which removes the new line.
//It will also print environmental varible if they are called.
void	ft_echo(char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 1;
	while (argv[i])
		i++;
	if (i >= 2 && ft_strcmp(argv[1], "-n"))
		k = 2;
	echo_flag(argv, i, j, k);
}
