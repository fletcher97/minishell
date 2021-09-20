/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:54:06 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/20 12:05:34 by falmeida         ###   ########.fr       */
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

	if (!mini->argv[0])
		return ;
	argv[0] = mini->argv[0];
	argv[1] = mini->argv[1];
	argv[2] = NULL;

	if (str_cmp_both_len(mini->argv[0], "ls"))
		argv[1] = getcwd(mini->str, PATH_MAX);
	total = ft_strjoin(path, command);
	if (fork() == 0)
	{
		if ((execve(total, argv, NULL) == -1))
			error_output(mini, 'c');
	}
	else
		wait(NULL);
	free(total);
}
