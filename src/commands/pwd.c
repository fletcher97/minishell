/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:42 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/09 16:24:02 by fferreir         ###   ########.fr       */
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
	free_struct(mini, input);
	mini->exit = true;
	write(1, "exit\n", 4);
	kill(mini->pid, SIGINT);
}
