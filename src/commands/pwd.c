/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:29 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/11 19:26:56 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"

void	ft_pwd(void)
{
	print_env_content(g_mini.env, "PWD", 'n');
	printf("\n");
}

void	ft_exit(char *input)
{
	free_struct(input);
	g_mini.exit = 1;
	write(1, "exit\n", 4);
	kill(g_mini.pid, SIGINT);
}
