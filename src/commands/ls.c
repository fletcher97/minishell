/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:54:06 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/09 14:09:28 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ls(t_mini *mini)
{
	mini->str = NULL;
	char *path = "/bin/";
	char *command = mini->argv[0];
	char *total;
	char* argv[3];

	argv[0] = mini->argv[0];
	argv[1] = mini->argv[1];
	argv[2] = NULL;

	if (!ft_strncmp(mini->argv[0], "ls", ft_strlen(mini->argv[0])))
		argv[1] = getenv("PWD");
	total = ft_strjoin(path, command);
	if (fork() == 0)
	{
		if ((execve(total, argv, NULL) == -1))
			error_output(mini, 'c');
	}
	else
		wait(NULL);
}


