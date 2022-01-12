/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:26 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/12 19:20:21 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

//The Path Creation function is used to differentiate between built-in program
//calls such as ls, wc, etc, and executable programs calls with "./" or "a.out")
static char	*path_creation(char *path, char *cmd)
{
	char		*temp;
	char		*new_path;
	t_dl_list	*head;

	head = g_mini.env;
	if (!ft_strncmp(cmd, "./", 2) || ft_strcmp(cmd, "a.out"))
		new_path = ft_strjoin(return_env_content(g_mini.env, "PWD"), ++cmd);
	else if (!ft_strncmp(cmd, "/", 1))
		new_path = ft_strdup(cmd);
	else
	{
		temp = ft_strjoin(path, "/");
		new_path = ft_strjoin(temp, cmd);
		free(temp);
		temp = NULL;
	}
	g_mini.env = head;
	return (new_path);
}

//The path creation loop function is mainly used to cut down lines on the execve
//function body. It will loop through all the possible path's found in the env
//"PATH" ($PATH) and try to run each of them with the inputed command.
//NOTA IMPORTANTE-> Criar copia do env interno em forma de table e null
//terminated e pasar para execve!
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
	return (127);
}

//The execve function is used to execute various commands such as ls, wc, grep
//etc. This commands are not mandatory but will improve the user experience and
//they will help during the program evaluation.
int	ft_execve(char **argv, int i)
{
	char	*path;
	char	**paths;
	int		j;

	if (!argv[i])
		return (0);
	path = return_env_content(g_mini.env, "PATH");
	paths = ft_split((const char *)path, ':');
	g_mini.str = NULL;
	j = path_creation_loop(argv, paths, argv[i]);
	if (j == 127)
		error_output('c', 0, NULL);
	exit(127);
	return (j);
}
