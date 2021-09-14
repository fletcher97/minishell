/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:11 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/14 11:51:38 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	screening(t_mini *mini, char *input)
{
	int x = 0;

	while (mini->argv[++x])
		;
	if (mini->argv)
	{
		if (!ft_strncmp(mini->argv[0], "pwd", ft_strlen(mini->argv[0])))
			ft_pwd();
		else if (!ft_strncmp(mini->argv[0], "exit", ft_strlen(mini->argv[0])))
			ft_exit(mini, input);
		else if (!ft_strncmp(mini->argv[0], "echo", ft_strlen(mini->argv[0])))
			ft_echo(mini);
		else if (!ft_strncmp(mini->argv[0], "cd", ft_strlen(mini->argv[0])))
			ft_cd(mini);
		else if (!ft_strncmp(mini->argv[0], " ", ft_strlen(mini->argv[0])))
			printf("\n");
		else if(!ft_strncmp(mini->argv[0], "env", ft_strlen(mini->argv[0])))
				ft_env(mini);
		else if(!ft_strncmp(mini->argv[0], "export", ft_strlen(mini->argv[0])))
			ft_export(mini);
		else if(!ft_strncmp(mini->argv[0], "node", ft_strlen(mini->argv[0])))
		{
			if (ft_strlen(mini->argv[1]) > 0)
				ft_lstnode_print(mini->env, mini->argv[1]);
		}
		else if (!ft_strncmp(mini->argv[0], "unset", ft_strlen(mini->argv[0])))
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

void	get_signal(int signal)
{
	if (signal == SIGHUP)
		return ;
}

int main(int argc, char **argv, char **env)
{
	t_mini	mini;
	char	*input;
	// TESTE
	//char *envt[5]={"primeiro=1","segundo=2","terceiro=3","quarto=5",0};
	//(void)env;
	// END TESTES
	(void) argc;
	(void) argv;
	//char **temp;
	//temp = env;
	mini.head = malloc(sizeof(t_list));
	mini.pid = getpid();
	mini.env = get_env(env, &mini);
	mini.exit = false;

	while (42)
	{
		input = readline("minishell: ");
	//	printf("input = |%s| |%zu|\n", input, strlen(input));
		if (ft_strlen(input) != 0)
		{
			signal(mini.pid, get_signal);
			add_history(input);
			mini.argv = ft_split(input, ' ');
			screening(&mini, input);
			// if (mini.exit == true)
			// {
			// 	printf("exiting...\n");
			// 	free_struct(&mini, input);
			// 	exit (0);
			// }
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
