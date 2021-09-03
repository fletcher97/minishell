/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:54:06 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/03 21:59:40 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ls(t_mini *mini)
{
	mini->str = NULL;

	char *path = "/bin/";
	char* argv[] = { mini->argv[0], getwd(mini->str) ,NULL};
	char *command = mini->argv[0];
	char *total;

	total = ft_strjoin(path, command);

	pid_t num;

	num = fork();

	if (num == 0)
		execve(total, argv, NULL);
	else
		return ;

}


