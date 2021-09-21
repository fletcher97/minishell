/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:42 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/21 16:19:19 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*pwd(void)
{
	char *str;

	str = NULL;
	str = getcwd(str, PATH_MAX);
	return (str);
}

void	ft_pwd(void)
{
	printf("%s\n", pwd());
}

void	ft_exit(char *input)
{
	free_struct(input);
	mini.exit = true;
	write(1, "exit\n", 4);
	kill(mini.pid, SIGINT);
}
