/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 05:11:37 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/06 22:33:09 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "minishell.h"

t_mini	g_mini;

// #define TRUE(x) x?'1':'0'
// #define BYTES(x) TRUE(x&0x80),TRUE(x&0x40),TRUE(x&0x20),TRUE(x&0x10),\
// TRUE(x&0x8),TRUE(x&0x4),TRUE(x&0x2),TRUE(x&0x1)

// void print_tree(t_tree *t, int lvl)
// {
// 	printf("%*s[%p] \n", lvl, "", t);
// 	t_cmd *cmd= (t_cmd*)t->content;
// 	if (cmd)
// 	{
// 		printf("%*s{flags:[", lvl, "");
// 		if (cmd->cmd_flags & 1)
// 			printf(" WILDE ");
// 		if (cmd->cmd_flags & 2)
// 			printf(" EXITE ");
// 		if (cmd->cmd_flags & 4)
// 			printf(" AND ");
// 		if (cmd->cmd_flags & 8)
// 			printf(" OR ");
// 		if (cmd->cmd_flags & 0x10)
// 			printf(" END ");
// 		if (cmd->cmd_flags & 0x20)
// 			printf(" RES ");
// 		if (cmd->cmd_flags & 0x40)
// 			printf(" PIPE ");
// 		if (cmd->line)
// 		printf("] line: ---%s--- cmd: [", cmd->line);
// 		if (cmd->cmd)
// 			for (int i = 0; cmd->cmd[i]; i++)
// 				printf(" ---%s--- ", cmd->cmd[i]);
// 		printf("] in:{ INPUT:[");
// 		for (t_list *l = cmd->in.input; l; l = l->next)
// 			printf(" %s ", (char*)l->content);
// 		printf("] HEREDOC:[");
// 		for (t_list *l = cmd->in.heredoc; l; l = l->next)
// 			printf(" %s ", (char*)l->content);
// 		printf("] OUTPUT:[");
// 		for (t_list *l = cmd->in.output; l; l = l->next)
// 			printf(" %s ", (char*)l->content);
// 		printf("] APPEND:[");
// 		for (t_list *l = cmd->in.append; l; l = l->next)
// 			printf(" %s ", (char*)l->content);
// 		printf("] in:");
// 		if (cmd->in.in)
// 			printf(" %s", (char*)((t_list*)cmd->in.in)->content);
// 		printf(" out:");
// 		if (cmd->in.out)
// 			printf(" %s", (char*)((t_list*)cmd->in.out)->content);
// 		printf(" }\n");
// 	}
// 	else
// 		printf("%*s{}\n", lvl, "");
// 	for (int i = 0; i < t->lcount; i++)
// 		print_tree(t->leafs[i], lvl + 1);
// }

// void print_cmd(t_commands *cmd)
// {
// 	printf("Error: %d\n", cmd->error);
// 	printf("Line: %s\n", cmd->line);
// 	print_tree(cmd->tree, 0);
// }

int	main(int argc, char const *argv[])
{
	t_commands	*cmd;

	if (argc == 1)
		return (0);
	printf("validating: ---%s---\n", argv[1]);
	cmd = validate(argv[1]);
	if (!cmd->error)
		printf("valide\n");
	else
		printf("Error: %d\n", cmd->error);
	// cmd = parse(argv[1]);
	// print_cmd(cmd);
	// free_command(cmd);
	free(cmd);
	return (0);
}
