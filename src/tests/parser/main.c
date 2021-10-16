/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 05:11:37 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/16 11:08:07 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "minishell.h"

t_mini	g_mini;

void	print_cmd(t_commands *cmd)
{
	int	i;

	if (cmd->error)
		printf("err: %d\n", cmd->error);
	if (cmd->cmd)
		printf("cmd: ---%s---\n", cmd->cmd);
	if (cmd->line)
		printf("line: ---%s---\n", cmd->line);
	i = -1;
	if (cmd->args)
		while (cmd->args[++i])
			printf("arg %d: ---%s---\n", i, cmd->args[i]);
	if (cmd->input)
		printf("in: ---%s---\n", cmd->input);
	if (cmd->output)
		printf("out: ---%s---\n", cmd->output);
}

void	clear_cmd(t_commands *cmd)
{
	int	i;

	if (cmd->cmd)
		free(cmd->cmd);
	i = -1;
	if (cmd->line)
		free(cmd->line);
	if (cmd->args)
		while (cmd->args[++i])
			free(cmd->args[i]);
	if (cmd->args)
		free(cmd->args);
	if (cmd->input)
		free(cmd->input);
	if (cmd->output)
		free(cmd->output);
}

int	main(int argc, char const *argv[])
{
	t_commands	*cmd;

	if (argc == 1)
		return (0);
	printf("parsing: ---%s---\n", argv[1]);
	cmd = parse(argv[1]);
	print_cmd(cmd);
	clear_cmd(cmd);
	free(cmd);
	return (0);
}
