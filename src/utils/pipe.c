/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:57:44 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/14 16:19:54 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

//The screening pipe function is a sorter. It will receive and integer
//regarding the argument it is working (command) and it will call the matching
//command function.
static int	screening_pipe(int i)
{
	if (g_mini.argv)
	{
		if (ft_strcmp(g_mini.argv[i], "pwd"))
			ft_pwd(g_mini.env);
		else if (ft_strcmp(g_mini.argv[i], "echo"))
			ft_echo(g_mini.argv);
		else if (ft_strcmp(g_mini.argv[i], "cd"))
			ft_cd(g_mini.argv);
		else if (ft_strcmp(g_mini.argv[i], " "))
			printf("\n");
		else if (ft_strcmp(g_mini.argv[i], "env"))
			ft_env(g_mini.env);
		else if (ft_strcmp(g_mini.argv[i], "export"))
			ft_export(g_mini.argv);
		else if (ft_strcmp(g_mini.argv[i], "unset"))
			ft_unset(g_mini.env, g_mini.argv, i);
		else
			ft_execve(g_mini.argv, i);
	}
	return (i);
}

//The piper function will execute 2 commands separated by a pipe.
//Right now the parse will not let it do multiple pipes. For that, we will need
//to set up a while loop so it go through all the commands on a list.
int	piper(int i)
{
	int	pipefd[2];
	int	pid;

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		i -= 1;
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		screening_pipe(i);
		close(pipefd[1]);
		exit(1);
	}
	else
	{
		i += 1;
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		wait(NULL);
		screening_pipe(i);
		close(pipefd[0]);
	}
	return (0);
}
