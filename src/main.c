/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:17:23 by fletcher          #+#    #+#             */
/*   Updated: 2022/02/10 10:35:14 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

#include "readline.h"
#include "history.h"

#include "ft_stdlib.h"
#include "ft_string.h"

#include "minishell.h"
#include "parser.h"
#include "utilities.h"
#include "execution.h"

void print_cmd(t_commands *cmd);

t_mini	g_mini;

/*
*   Tree loop function will check the tree leafs for commands. Also, it is
*    responsible for setting up the FD initial logic and retrieving exit
*    status variable from child process's.
*/
void tree_loop(t_tree *t, int i, int init)
{
	int		status;
	int flag;
	static int step = 0;
	t_cmd	*cmd;

	if (!t)
		return ;
	cmd = (t_cmd *)t->content;
	flag = 0;
	if (cmd && cmd->cmd && cmd->cmd[0])
	{
		if (init)
			dup_init_and_close('i');
		g_mini.hdoc_counter = step;
		g_mini.argv = cmd->cmd;
		if (cmd->cmd_flags & 0x40)
		{
			command_exec(cmd);
			return ;
		}
		command_exec(cmd);
		status = dup_init_and_close('c');
		(g_mini.pid > 0) && (waitpid(g_mini.pid, &status, 0));
		if (WIFEXITED(status))
			g_mini.exit_status = WEXITSTATUS(status);

	}
	else
	{
		while (i < t->lcount)
		{
			if (flag && ((((t_cmd *)(t->leafs[i]->content))->cmd_flags & 0x4 && g_mini.exit_status)
				|| (((t_cmd *)(t->leafs[i++]->content))->cmd_flags & 0x8 && !g_mini.exit_status)))
			{
				step += 10;
				continue ;
			}
			if (i < t->lcount)
			{
				step += 10;
				tree_loop(t->leafs[i], 0, !flag || (i > 0 && !(((t_cmd *)t->leafs[i -1]->content)->cmd_flags & 0x40)));
			}
			if (i >= t->lcount || !t->leafs[i]->content)
				break ;
			flag = 1;
		}
	}
}

/*
*   The input loop is used to cut down some lines on the main function body.
*/
static void	input_loop(char *input)
{
	t_commands	*cmd;

	g_mini.input = input;
	g_mini.first_cmd = 1;
	add_history(input);
	cmd = parse(input);
	if (!cmd->error)
	{
		g_mini.cmd = cmd;
		check_heredoc(cmd->tree);
		g_mini.hdoc_counter = 0;
		tree_loop(cmd->tree, 0, 0);
		delete_temp(g_mini.temp_path);
	}
	else
		printf("Syntax error code: %d\n", cmd->error);
	free_command(cmd);
	ft_free(input);
	re_init();
	input = NULL;
}

/*
*   The main function is responsible for receiving the input from the user and
*   manage it. It will make sure the program has a promp until the used call for
*   exit or sends the signal do quit.
*/
int	main(int argc, char **argv, char **env)
{
	char	*input;

	(void) argc;
	(void) argv;
	struct_init(env);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, hsi);
	while (42)
	{
		input = readline("minishell: ");
		if (input && ft_strlen(input) != 0)
			input_loop(input);
		else if (input)
			ft_free(input);
		if (g_mini.exit || !input)
			exit_loop();
	}
	return (0);
}
