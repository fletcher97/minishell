/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:26 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/12 15:59:07 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_ls(int i)
{
	char	*path;
	char	*total;
	char	**argv;

	path = "/usr/bin/";
	g_mini.str = NULL;
	if (!g_mini.argv[i])
		return ;
	argv = (char *[]){g_mini.argv[i], g_mini.argv[i + 1], NULL};
	if (ft_strcmp(argv[i], "ls"))
	{
		path = "/bin/";
		argv[1] = getcwd(g_mini.str, PATH_MAX);
	}
	total = ft_strjoin(path, argv[i]);
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
