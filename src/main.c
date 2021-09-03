/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:11 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/03 18:35:12 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	screening(char* str, int pid)
{
	if (!str)
		return ;
	else if (!ft_strncmp(str, "pwd", ft_strlen(str)))
		ft_pwd();
	else if (!ft_strncmp(str, "exit", ft_strlen(str)))
		ft_exit(pid);
	else if (!ft_strncmp(str, "echo", 4))
		ft_echo(str);
	else if (!ft_strncmp(str, "cd", ft_strlen(str)))
		ft_cd();
	else
	{
		printf("minishell: %s: command not found\n", str);
		return ;
	}
}

int main()
{
	char	*inpt;
	int		pid;

	pid = getpid();
	while (42)
	{
		inpt = readline("minishell: ");
		add_history(inpt);
		screening(inpt, pid);
	}
	return (0);
}
