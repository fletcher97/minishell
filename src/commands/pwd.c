/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:29 by mgueifao          #+#    #+#             */
/*   Updated: 2021/11/08 15:10:51 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

//Print the content of the environmental variable "PWD" from the internal
//env list (dual linked list).

int	ft_pwd(void)
{
	char	pwd[PATH_MAX];

	if (!getcwd(pwd, PATH_MAX))
		return (-1);
	printf("%s\n", pwd);
	return (1);
}

//Exit function is used to flag the exit call to make sure that the main func
//free up our struct and exit the program successfully.
//free_struct function is being called inside the main loop now when the exit
//is called.
void	ft_exit(void)
{
	g_mini.exit = 1;
	write(1, "exit\n", 4);
}
