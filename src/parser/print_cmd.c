/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:44:20 by mgueifao          #+#    #+#             */
/*   Updated: 2021/11/11 22:45:52 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "parser.h"

static void	print_flags(t_cmd *cmd, int lvl)
{
	printf("%*s{flags:[", lvl, "");
	if (cmd->cmd_flags & 1)
		printf(" WILDE ");
	if (cmd->cmd_flags & 2)
		printf(" EXITE ");
	if (cmd->cmd_flags & 4)
		printf(" AND ");
	if (cmd->cmd_flags & 8)
		printf(" OR ");
	if (cmd->cmd_flags & 0x10)
		printf(" END ");
	if (cmd->cmd_flags & 0x20)
		printf(" RES ");
	if (cmd->cmd_flags & 0x40)
		printf(" PIPE ");
}

static void	print_io(t_cmd *cmd)
{
	printf("] line: ---%s--- cmd: [", cmd->line);
	if (cmd->cmd)
		for (int i = 0; cmd->cmd[i]; i++)
			printf(" ---%s--- ", cmd->cmd[i]);
	printf("] in:{ INPUT:[");
	for (t_list *l = cmd->in.input; l; l = l->next)
		printf(" %s ", (char *)l->content);
	printf("] HEREDOC:[");
	for (t_list *l = cmd->in.heredoc; l; l = l->next)
		printf(" %s ", (char *)l->content);
	printf("] OUTPUT:[");
	for (t_list *l = cmd->in.output; l; l = l->next)
		printf(" %s ", (char *)l->content);
	printf("] APPEND:[");
	for (t_list *l = cmd->in.append; l; l = l->next)
		printf(" %s ", (char *)l->content);
	printf("] in:");
	if (cmd->in.in)
		printf(" %s", (char *)((t_list *)cmd->in.in)->content);
	printf(" out:");
	if (cmd->in.out)
		printf(" %s", (char *)((t_list *)cmd->in.out)->content);
	printf(" }\n");
}

static void	print_tree(t_tree *t, int lvl)
{
	printf("%*s[%p] \n", lvl, "", t);
	t_cmd *cmd = (t_cmd*)t->content;
	if (cmd)
	{
		print_flags(cmd, lvl);
		print_io(cmd);
	}
	else
		printf("%*s{}\n", lvl, "");
	for (int i = 0; i < t->lcount; i++)
		print_tree(t->leafs[i], lvl + 1);
}

void print_cmd(t_commands *cmd)
{
	printf("Error: %d\n", cmd->error);
	printf("Line: %s\n", cmd->line);
	print_tree(cmd->tree, 0);
}
