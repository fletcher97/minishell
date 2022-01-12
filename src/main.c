/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:17:23 by fletcher          #+#    #+#             */
/*   Updated: 2022/01/12 20:08:18 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "minishell.h"
#include "parser.h"

t_mini	g_mini;

//Struct init function is used to initiate the stuct variable and cut down some
//lines in the main function body.
static void	struct_init(char **env)
{
	int	i;

	g_mini.head = malloc(sizeof(t_dl_list));
	g_mini.env = get_env(env);
	g_mini.exit = 0;
	g_mini.exit_status = 0;
	g_mini.fd_in = 0;
	g_mini.fd_out = 1;
	g_mini.hdoc_counter = 0;
	g_mini.temp_path = ft_strdup("/tmp/	");
	i = -1;
	g_mini.hdoc_files = malloc(sizeof(char **) * (FD_MAX + 1));
	while (++i < FD_MAX)
		g_mini.hdoc_files[i] = ft_itoa(i);
	g_mini.hdoc_files[i] = NULL;
	g_mini.pid_lst = malloc(sizeof(int*) * (CHILD_MAX + 1));
	i = -1;
	while (++i < CHILD_MAX)
		g_mini.pid_lst[i] = -1;
	g_mini.pid_lst[i] = 0;
	g_mini.file_counter = 0;
	g_mini.cmd_counter = 0;
	g_mini.and_flag = 0;
	g_mini.stop = 0;
	g_mini.pid_counter = -1;
}

static int	check_cmd_calls(t_tree *t)
{
	t_cmd		*cmd;
	static int	step;

	cmd = (t_cmd *)t->content;
	step += 10;
	if (!cmd)
		return (0);
	g_mini.argv = cmd->cmd;
	g_mini.hdoc_counter = step;
	if (command_exec(cmd) == -1)
		return (-1);
	return (1);
}

static void tree_loop(t_tree *t)
{
	int	status;
	int	i;

	g_mini.tmp_in = dup(0);
	g_mini.tmp_out = dup(1);
	g_mini.fd_in = dup(g_mini.tmp_in);
	i = -1;
	while (++i < t->lcount)
	{
		if (check_cmd_calls(t->leafs[i]) == -1)
			break ;
	}
	dup2(g_mini.tmp_in, 0);
	dup2(g_mini.tmp_out, 1);
	close(g_mini.tmp_in);
	close(g_mini.tmp_out);
	status = 0;
	if (g_mini.pid > 0)
		waitpid(g_mini.pid, &status, 0);
	if (WIFEXITED(status))
		g_mini.exit_status = WEXITSTATUS(status);
}


//The input loop is used to cut down some lines on the main function body.
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
		tree_loop(cmd->tree);
		delete_temp(g_mini.temp_path);
	}
	else
		printf("Syntax error code: %d\n", cmd->error);
	free_command(cmd);
	free(input);
	re_init();
	input = NULL;
}

//The main function is 	responsible for receiving the input from the user and
//manage it. It will make sure the program has a promp until the used call for
//exit or sends the signal do quit.
int	main(int argc, char **argv, char **env)
{
	char	*input;
	int		i;

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
		if (g_mini.exit)
		{
			free_dl_list(g_mini.env);
			i = -1;
			while (++i < FD_MAX)
				ft_free(g_mini.hdoc_files[i]);
			free(g_mini.hdoc_files);
			free(g_mini.pid_lst);
			exit(0);
		}
	}
	return (0);
}
