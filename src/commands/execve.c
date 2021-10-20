/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:26 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/20 18:50:35 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

//The Path Creation function is used to differentiate between built-in program
//calls such as ls, wc, etc, and executable programs calls with "./" or "a.out")
static char	*path_creation(char *path, char *cmd)
{
	char	*temp;
	char	*new_path;

	if (!ft_strncmp(cmd, "./", 2) || ft_strcmp(cmd, "a.out"))
		new_path = ft_strjoin(return_env_content(g_mini.env, "PWD"), ++cmd);
	else
	{
		temp = ft_strjoin(path, "/");
		new_path = ft_strjoin(temp, cmd);
		free(temp);
		temp = NULL;
	}
	return (new_path);
}

//The path creation loop function is mainly used to cut down lines on the execve
//function body. It will loop through all the possible path's found in the env
//"PATH" ($PATH) and try to run each of them with the inputed command.
static int	path_creation_loop(char **cmds, char **path, char *cmd)
{
	char	*total;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (path[++i])
	{
		total = path_creation(path[i], cmd);
		if ((execve(total, cmds, NULL) != -1))
			--j;
		free(total);
		total = NULL;
		++j;
	}
	if (j == i)
		return (1);
	return (0);
}

//The execve function is used to execute various commands such as ls, wc, grep
//etc. This commands are not mandatory but will improve the user experience and
//they will help during the program evaluation.
void	ft_execve(char **argv, int i)
{
	char	*path;
	char	**cmd;
	char	**paths;
	int		j;

	path = return_env_content(g_mini.env, "PATH");
	paths = ft_split((const char *)path, ':');
	g_mini.str = NULL;
	if (!argv[i])
		return ;
	cmd = (char *[]){argv[i], argv[i + 1], NULL};
	if (ft_strcmp(cmd[0], "ls"))
		cmd[1] = getcwd(g_mini.str, PATH_MAX);
	if (fork() == 0)
	{
		j = path_creation_loop(cmd, paths, cmd[i]);
		if (j == 0)
			error_output('c', 0);
		kill(getpid(), SIGINT);
	}
	else
		wait(&g_mini.errno);
	printf("ES = |%d|\n", g_mini.errno);
}
