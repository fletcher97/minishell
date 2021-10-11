/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:17:23 by fletcher          #+#    #+#             */
/*   Updated: 2021/10/11 19:24:50 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini	g_mini;

static void	screening_two(int i)
{
	if (ft_strcmp(g_mini.argv[i], "pwd") || ft_strcmp(g_mini.argv[i], "PWD"))
		ft_pwd();
	else if (ft_strcmp(g_mini.argv[i], "export"))
		ft_export();
	else if (ft_strcmp(g_mini.argv[i], "node"))
	{
		if (ft_strlen(g_mini.argv[i]) > 0)
			ft_lstnode_print(g_mini.env, g_mini.argv[i + 1]);
	}
	else if (ft_strcmp(g_mini.argv[i], "unset"))
		ft_unset();
	else
		ft_ls(i);
}

static void	screening_one(char *input)
{
	int	i;

	i = find_special();
	if (i == -1)
		return ;
	if (g_mini.argv && i == 0)
	{
		if (ft_strcmp(g_mini.argv[i], "exit"))
			ft_exit(input);
		else if (ft_strcmp(g_mini.argv[i], "echo"))
			ft_echo();
		else if (ft_strcmp(g_mini.argv[i], "cd"))
			ft_cd();
		else if (ft_strcmp(g_mini.argv[i], " "))
			printf("\n");
		else if (ft_strcmp(g_mini.argv[i], "env"))
			ft_env();
		else
			screening_two(i);
	}
}

static void	struct_init(char **env)
{
	g_mini.head = malloc(sizeof(t_dl_list));
	g_mini.pid = getpid();
	g_mini.env = get_env(env);
	g_mini.exit = 0;
}

static void	input_loop(char *input)
{
	add_history(input);
	g_mini.argv = ft_split(input, ' ');
	g_mini.nbr_arg = args_counter();
	screening_one(input);
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
			free_struct(input);
			free_lst(g_mini.env);
			exit(0);
		}
		input = readline("minishell: ");
	}
	return (0);
}
