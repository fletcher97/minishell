/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:57:44 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/05 22:57:46 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	screening_pipe(int i)
{
	if (g_mini.argv)
	{
		if (ft_strcmp(g_mini.argv[i], "pwd"))
			ft_pwd();
		else if (ft_strcmp(g_mini.argv[i], "echo"))
			ft_echo();
		else if (ft_strcmp(g_mini.argv[i], "cd"))
			ft_cd();
		else if (ft_strcmp(g_mini.argv[i], " "))
			printf("\n");
		else if (ft_strcmp(g_mini.argv[i], "env"))
			ft_env();
		else if (ft_strcmp(g_mini.argv[i], "export"))
			ft_export();
		else if (ft_strcmp(g_mini.argv[i], "unset"))
			ft_unset();
		else
			ft_ls(i);
	}
	return (i);
}

// STDOUT para write pipe
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
