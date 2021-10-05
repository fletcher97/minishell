/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:29 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/05 22:30:31 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(void)
{
	print_env_content(g_mini.env, "PWD", 'n');
	printf("\n");
}

void	ft_exit(char *input)
{
	free_struct(input);
	g_mini.exit = true;
	write(1, "exit\n", 4);
	kill(g_mini.pid, SIGINT);
}
