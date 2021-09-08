/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:42 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/08 17:47:24 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *pwd(void)
{
    char *str;
	str = getenv("PWD");

    return (str);
}

void	ft_pwd(void)
{
	printf("%s\n", pwd());
}

void	ft_exit(t_mini *mini, char *input)
{
	int pid;

	pid = mini->pid;
	free_struct(mini, input);
	write(1, "exit", 4);
	kill(pid, SIGINT);
}
