/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:17:23 by fletcher          #+#    #+#             */
/*   Updated: 2021/11/11 22:45:28 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

t_mini	g_mini;

static void	screening_two(int i)
{
	if (ft_strcmp(g_mini.argv[i], "pwd") || ft_strcmp(g_mini.argv[i], "PWD"))
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
		ft_execve(g_mini.argv, i);
}

static void	screening_one(char **argv)
{
	int	i;

	i = find_special();
	if (i == -1)
		return ;
	if (g_mini.argv && i == 0)
	{
		if (ft_strcmp(argv[i], "exit"))
			ft_exit();
		else if (ft_strcmp(argv[i], "echo"))
			ft_echo(argv);
		else if (ft_strcmp(argv[i], "cd"))
			ft_cd(argv);
		else if (ft_strcmp(argv[i], " "))
			printf("\n");
		else if (ft_strcmp(argv[i], "env"))
			ft_env(g_mini.env);
		else
			screening_two(i);
	}
}

//Struct init function is used to initiate the stuct variable and cut down some
//lines in the main function body.
static void	struct_init(char **env)
{
	g_mini.head = malloc(sizeof(t_dl_list));
	g_mini.pid = getpid();
	g_mini.env = get_env(env);
	g_mini.exit = 0;
	g_mini.errno = 0;
}

//The input loop is used to cut down some lines on the main function body.
//PS: Removed "g_mini.nbr_arg = args_counter();" because the variable is not
//being used atm.
static void	input_loop(char *input)
{
	t_commands	*cmd;

	add_history(input);
	cmd = parse(input);
	print_cmd(cmd);
	free_command(cmd);
	g_mini.argv = ft_split(input, ' ');
	screening_one(g_mini.argv);
	free_argv();
	free(input);
	input = NULL;
}

// before while
//	signal(SIGINT , get_signal);
//	signal(SIGQUIT , get_signal);
// while start
//	input = readline("minishell: ");
//	printf("input = %s\n", input);
//The main function is responsible for receiving the input from the user and
//manage it. It will make sure the program has a promp until the used call for
//exit or sends the signal do quit.
int	main(int argc, char **argv, char **env)
{
	char	*input;

	(void) argc;
	(void) argv;
	struct_init(env);
	input = readline("minishell: ");
	while (input)
	{
		if (input && ft_strlen(input) != 0)
			input_loop(input);
		if (g_mini.exit == 1)
		{
			free_dl_list(g_mini.env);
			exit(0);
		}
		input = readline("minishell: ");
	}
	return (0);
}
