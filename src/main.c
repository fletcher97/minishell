/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:11 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/22 12:25:51 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void	screening(char *input)
{
	find_special();
	if (mini.argv)
	{
		if (ft_strcmp(mini.argv[0], "pwd"))
			ft_pwd();
		else if (ft_strcmp(mini.argv[0], "exit"))
			ft_exit(input);
		else if (ft_strcmp(mini.argv[0], "echo"))
			ft_echo();
		else if (ft_strcmp(mini.argv[0], "cd"))
			ft_cd();
		else if (ft_strcmp(mini.argv[0], " "))
			printf("\n");
		else if(ft_strcmp(mini.argv[0], "env"))
				ft_env();
		else if(ft_strcmp(mini.argv[0], "export"))
			ft_export();
		else if(ft_strcmp(mini.argv[0], "node"))
		{
			if (ft_strlen(mini.argv[1]) > 0)
				ft_lstnode_print(mini.env, mini.argv[1]);
		}
		else if (ft_strcmp(mini.argv[0], "unset"))
			ft_unset();
		else
			ft_ls();
	}
	else
		return ;
}

int main(int argc, char **argv, char **env)
{

	char	*input;

	(void) argc;
	(void) argv;
	mini.head = malloc(sizeof(t_list));
	mini.pid = getpid();
	mini.env = get_env(env);
	mini.exit = false;

	//signal(SIGINT , get_signal);
	//signal(SIGQUIT , get_signal);
	while (42)
	{
		input = readline("minishell: ");
		if (input && ft_strlen(input) != 0)
		{
			add_history(input);
			mini.argv = ft_split(input, ' ');
			screening(input);
			free_argv();
			free(input);
			input = NULL;
		}
		if (mini.exit == true)
		{
			free_struct(input);
			free_lst(mini.env);
			exit(0);
		}
	}
	return (0);
}
