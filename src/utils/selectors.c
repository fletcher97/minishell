/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:28:26 by fferreir          #+#    #+#             */
/*   Updated: 2021/12/16 16:37:39 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

static int	screening_two(int i)
{
	if (ft_strcmp(g_mini.argv[i], "pwd"	))
		ft_pwd();
	else if (ft_strcmp(g_mini.argv[i], "export"))
		ft_export(g_mini.argv);
	else if (ft_strcmp(g_mini.argv[i], "node"))
	{
		if (ft_strlen(g_mini.argv[i]) > 0)
			ft_lstnode_print(g_mini.env, g_mini.argv[i + 1]);
	}
	else if (ft_strcmp(g_mini.argv[i], "unset"))
		ft_unset(g_mini.env, g_mini.argv, i);
	else
		i = 1;
	return (i);
}

int	screening_one(char **argv)
{
	int	i;

	i = 0;
	if (g_mini.argv)
	{
		if (ft_strcmp(argv[i], "exit"))
			ft_exit();
		else if (ft_strcmp(argv[i], "echo"))
			ft_echo(argv);
		else if (ft_strcmp(argv[i], "cd"))
			i = ft_cd(argv);
		else if (ft_strcmp(argv[i], " "))
			printf("\n");
		else if (ft_strcmp(argv[i], "env"))
			ft_env(g_mini.env);
		else
			i = screening_two(i);
	}
	return (i);
}

void	cmd_selector(char **argv)
{
	if (argv[0])
	{
		if (ft_strcmp(argv[0], "echo"))
			ft_echo(argv);
		else if (ft_strcmp(argv[0], "env"))
			ft_env(g_mini.env);
		else
			ft_execve(argv, 0);
	}
}

int	cmd_identifier(char **argv)
{
	int	i;

	i = 0;
	if (g_mini.argv)
	{
		if (ft_strcmp(argv[i], "exit"))
			i = 0;
		else if (ft_strcmp(argv[i], "cd"))
			i = 0;
		else if (ft_strcmp(argv[i], " "))
			i = 0;
		else if (ft_strcmp(argv[i], "pwd") || ft_strcmp(g_mini.argv[i], "PWD"))
			i = 0;
		else if (ft_strcmp(argv[i], "export"))
			i = 0;
		else if (ft_strcmp(argv[i], "node"))
			i = 0;
		else if (ft_strcmp(argv[i], "unset"))
			i = 0;
		else
			i = 1;
	}
	return (i);
}
