/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:11 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/03 20:24:15 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	screening(t_mini *mini)
{
	if (!mini->argv[0])
		return ;
	else if (!ft_strncmp(mini->argv[0], "pwd", ft_strlen(mini->argv[0])))
		ft_pwd();
	else if (!ft_strncmp(mini->argv[0], "exit", ft_strlen(mini->argv[0])))
		ft_exit(mini->pid);
	else if (!ft_strncmp(mini->argv[0], "echo", 4))
		ft_echo(mini);
	else if (!ft_strncmp(mini->argv[0], "cd", ft_strlen(mini->argv[0])))
		ft_cd();
	else
	{
		printf("minishell: %s: command not found\n", mini->argv[0]);
		return ;
	}
}

int	find_char(char	*str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int main()
{
	t_mini	mini;
	char	*input;

	mini.pid = getpid();
	while (42)
	{
		input = readline("minishell: ");
		add_history(input);
		mini.argv = ft_split(input, ' ');
		screening(&mini);
	}
	return (0);
}
