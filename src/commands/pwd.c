/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:42 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/03 18:35:53 by falmeida         ###   ########.fr       */
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

void	ft_exit(int pid)
{
	write(1, "exit", 4);
	kill(pid, SIGINT);
}
