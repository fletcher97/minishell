/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:29 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/14 15:28:09 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

//Print the content of the environmental variable "PWD" from the internal
//env list (dual linked list).

void	ft_pwd(t_dl_list *env)
{
	print_env_content(env, "PWD", 'n');
	printf("\n");
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
