/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:11 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/06 17:17:39 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	screening(t_mini *mini)
{
	if (mini->argv)
	{
		if (!ft_strncmp(mini->argv[0], "pwd", ft_strlen(mini->argv[0])))
			ft_pwd();
		else if (!ft_strncmp(mini->argv[0], "exit", ft_strlen(mini->argv[0])))
			ft_exit(mini->pid);
		else if (!ft_strncmp(mini->argv[0], "echo", ft_strlen(mini->argv[0])))
			ft_echo(mini->argv);
		else if (!ft_strncmp(mini->argv[0], "cd", ft_strlen(mini->argv[0])))
			ft_cd(mini);
		else
			ft_ls(mini);
	}
	else
		return ;
}

int main()
{
	t_mini	mini;
	char	*input;

	mini.pid = getpid();
	while (42)
	{
		input = readline("minishell: ");
		if (ft_strlen(input) > 0)
		{
			add_history(input);
			mini.argv = ft_split(input, ' ');
			screening(&mini);
		}
	}
	return (0);
}
