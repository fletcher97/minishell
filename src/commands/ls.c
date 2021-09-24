/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:54:06 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/24 16:10:26 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ls(int i)
{
	mini.str = NULL;
	char *path = "/usr/bin/";
	char *total;
	char* argv[3];

	if (!mini.argv[0])
		return ;
	argv[0] = mini.argv[i];
	argv[1] = mini.argv[i + 1];
	argv[2] = NULL;

	if (ft_strcmp(mini.argv[i], "ls"))
		argv[1] = getcwd(mini.str, PATH_MAX);
	total = ft_strjoin(path, argv[0]);
	if (fork() == 0)
	{
		if ((execve(total, argv, NULL) == -1))
			error_output('c', 0);
		kill(getpid(), SIGINT);
	}
	else
		wait(NULL);
	free(total);
}
