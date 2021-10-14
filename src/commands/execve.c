/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:26 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/14 16:19:24 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

//The execve function is used to execute various commands such as ls, wc, grep
//etc. This commands are not mandatory but will improve the user experience and
//they will help during the program evaluation.
void	ft_execve(char **argv, int i)
{
	char	*path;
	char	*total;
	char	**cmd;

	path = "/usr/bin/";
	g_mini.str = NULL;
	if (!argv[i])
		return ;
	cmd = (char *[]){argv[i], argv[i + 1], NULL};
	if (ft_strcmp(cmd[i], "ls"))
	{
		path = "/bin/";
		cmd[1] = getcwd(g_mini.str, PATH_MAX);
	}
	total = ft_strjoin(path, argv[i]);
	if (fork() == 0)
	{
		if ((execve(total, cmd, NULL) == -1))
			error_output('c', 0);
		kill(getpid(), SIGINT);
	}
	else
		wait(NULL);
	free(total);
}
