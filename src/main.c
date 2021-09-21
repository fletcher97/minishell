/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:11 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/21 14:11:09 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	screening(t_mini *mini, char *input)
{
	int x = 0;

	// while (mini->argv[++x])
	// 	;
	if (mini->argv)
	{
		if (str_cmp_both_len(mini->argv[0], "pwd"))
			ft_pwd();
		else if (str_cmp_both_len(mini->argv[0], "exit"))
			ft_exit(mini, input);
		else if (str_cmp_both_len(mini->argv[0], "echo"))
			ft_echo(mini);
		else if (str_cmp_both_len(mini->argv[0], "cd"))
			ft_cd(mini);
		else if (str_cmp_both_len(mini->argv[0], " "))
			printf("\n");
		else if(str_cmp_both_len(mini->argv[0], "env"))
				ft_env(mini);
		else if(str_cmp_both_len(mini->argv[0], "export"))
			ft_export(mini);
		else if(str_cmp_both_len(mini->argv[0], "node"))
		{
			if (ft_strlen(mini->argv[1]) > 0)
				ft_lstnode_print(mini->env, mini->argv[1]);
		}
		else if (str_cmp_both_len(mini->argv[0], "unset"))
		{
			if (x > 1)
				ft_unset(mini);
		}
		else
			ft_ls(mini);
	}
	else
		return ;
}

int main(int argc, char **argv, char **env)
{
	t_mini	mini;
	char	*input;

	(void) argc;
	(void) argv;
	mini.head = malloc(sizeof(t_list));
	mini.pid = getpid();
	mini.env = get_env(env, &mini);
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
			screening(&mini, input);
			free_argv(&mini);
			free(input);
			input = NULL;
		}
		if (mini.exit == true)
		{
			free_struct(&mini, input);
			free_lst(mini.env);
			exit(0);
		}
	}
	return (0);
}
