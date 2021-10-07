/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:05 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/07 16:25:38 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_content(t_dl_list *lst, char *name, char free_name)
{
	char	*content;

	content = NULL;
	if (return_env_content(lst, name))
	{
		content = return_env_content(lst, name);
		if (content == NULL)
			printf("\n");
		else
			printf("%s", content);
	}
	if (free_name == 'y')
		free(name);
}

char	*return_env_content(t_dl_list *lst, char *name)
{
	while (lst)
	{
		if (ft_strcmp(lst->name, name))
			break ;
		if (lst->next == NULL)
			return (NULL);
		lst = lst->next;
	}
	return (lst->content);
}

char	*env_flag_check(int i)
{
	char	*env_name;
	int		j;

	j = 0;
	env_name = NULL;
	while (g_mini.argv[i][j])
		j++;
	if (j > 0 && g_mini.argv[i][0] == '$')
	{
		env_name = ft_substr(g_mini.argv[i], 1, j);
		return (env_name);
	}
	return (NULL);
}

void	echo_flag(int i, int j, int k)
{
	if (i > k)
	{
		j = k;
		while (i > j)
		{
			if (env_flag_check(j) != NULL)
				print_env_content(g_mini.env, env_flag_check(j), 'y');
			else
				printf("%s", g_mini.argv[j]);
			if (i > 1 + j++)
				printf(" ");
		}
		if (k == 1)
			printf("\n");
	}
}

void	ft_echo(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 1;
	while (g_mini.argv[i])
		i++;
	if (i >= 2 && ft_strcmp(g_mini.argv[1], "-n"))
		k = 2;
	echo_flag(i, j, k);
}
