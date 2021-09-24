/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:11 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/24 18:59:14 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void	screening(char *input)
{
	int i;

	i = 0;
	if ((i = find_special()) == -1)
		return ;
	if (mini.argv && i == 0)
	{
		if (ft_strcmp(mini.argv[i], "pwd"))
			ft_pwd();
		else if (ft_strcmp(mini.argv[i], "exit"))
			ft_exit(input);
		else if (ft_strcmp(mini.argv[i], "echo"))
			ft_echo();
		else if (ft_strcmp(mini.argv[i], "cd"))
			ft_cd();
		else if (ft_strcmp(mini.argv[i], " "))
			printf("\n");
		else if(ft_strcmp(mini.argv[i], "env"))
				ft_env();
		else if(ft_strcmp(mini.argv[i], "export"))
			ft_export();
		else if(ft_strcmp(mini.argv[i], "node"))
		{
			if (ft_strlen(mini.argv[i]) > 0)
				ft_lstnode_print(mini.env, mini.argv[i + 1]);
		}
		else if (ft_strcmp(mini.argv[i], "unset"))
			ft_unset();
		else
			ft_ls(i);
	}
}

void	struct_init(char **env)
{
	mini.head = malloc(sizeof(t_list));
	mini.pid = getpid();
	mini.env = get_env(env);
	mini.exit = false;
}

int		args_counter()
{
	int i;

	i = 0;
	while (mini.argv[i])
		i++;
	return(i);
}

int main(int argc, char **argv, char **env)
{

	char	*input;
	(void) argc;
	(void) argv;
	int i = 0;

	struct_init(env);
	//signal(SIGINT , get_signal);
	//signal(SIGQUIT , get_signal);
	while (42)
	{
		if (i == 3)
			exit(1);
		input = readline("minishell: ");
		printf("input = %s\n", input);
		i++;
		if (input && ft_strlen(input) != 0)
		{
			add_history(input);
			mini.argv = ft_split(input, ' ');
			mini.nbr_arg = args_counter();
			screening(input);
			free_argv();
			free(input);
			input = NULL;
			i--;
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
