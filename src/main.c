/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:17:23 by fletcher          #+#    #+#             */
/*   Updated: 2021/12/07 17:20:49 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

t_mini	g_mini;

//Struct init function is used to initiate the stuct variable and cut down some
//lines in the main function body.
static void	struct_init(char **env)
{
	int	i;

	g_mini.head = malloc(sizeof(t_dl_list));
	g_mini.pid = getpid();
	g_mini.env = get_env(env);
	g_mini.exit = 0;
	g_mini.exit_status = 0;
	g_mini.errno = 0;
	g_mini.saved_fd = -1;
	g_mini.hdoc_counter = 0;
	g_mini.temp_path = ft_strdup("/tmp/	");
	i = -1;
	g_mini.hdoc_files = malloc(sizeof(char **) * (100 + 1));
	while (++i < 100)
		g_mini.hdoc_files[i] = ft_itoa(i);
	g_mini.hdoc_files[i] = NULL;
	g_mini.file_counter = 0;
}

void	printing(t_tree *t)
{
	t_cmd		*cmd;
	int			i;
	static int	step;

	cmd = (t_cmd *)t->content;
	i = -1;
	g_mini.exit_status = 0;
	step += 10;
	if (cmd)
	{
		g_mini.argv = cmd->cmd;
		g_mini.hdoc_counter = step;
		command_exec(cmd);
	}
	else
		for (int i = 0; i < t->lcount; i++)
		{
			if (g_mini.exit_status == -1)
			{
				printf("EXIT = %d\n", g_mini.exit_status);
				return ;
			}
			printing(t->leafs[i]);
		}
}

//The input loop is used to cut down some lines on the main function body.
//PS: Removed "g_mini.nbr_arg = args_counter();" because the variable is not
//being used atm.
static void	input_loop(char *input)
{
	t_commands	*cmd;

	g_mini.input = input;
	g_mini.first_cmd = 1;
	add_history(input);
	cmd = parse(input);
	g_mini.cmd = cmd;
	print_cmd(cmd);
	check_heredoc(cmd->tree);
	g_mini.hdoc_counter = 0;
	printing(cmd->tree);
	free_command(cmd);
	free(input);
	delete_temp(g_mini.temp_path);
	g_mini.hdoc_counter = 0;
	g_mini.file_counter = 0;
	input = NULL;
}

// before while
//	signal(SIGINT , get_signal);
//	signal(SIGQUIT , get_signal);
// while start
//	input = readline("minishell: ");
//The main function is 	responsible for receiving the input from the user and
//manage it. It will make sure the program has a promp until the used call for
//exit or sends the signal do quit.
int	main(int argc, char **argv, char **env)
{
	char	*input;

	(void) argc;
	(void) argv;
	struct_init(env);
	while (42)
	{
		input = readline("minishell: ");
		if (input && ft_strlen(input) != 0)
			input_loop(input);
		if (g_mini.exit)
		{
			free_dl_list(g_mini.env);
			free(g_mini.hdoc_files);
			exit(0);
		}
	}
	return (0);
}
