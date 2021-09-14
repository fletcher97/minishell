/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:15 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/14 16:25:55 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_content(t_list *lst, char *name)
{
	char *content;

	content = NULL;
	if (return_env_content(lst, name))
	{
		content = return_env_content(lst, name);
		printf("%s",content);
	}
	free(name);
}

char	*return_env_content(t_list *lst, char *name)
{
	while (lst)
	{
		if (str_cmp_both_len(lst->name, name))
			break ;
		lst = lst->next;
	}
	return (lst->content);
}

char	*env_flag_check(t_mini *mini, int i)
{
	char	*env_name;
	int j;

	j = 0;
	env_name = NULL;
	while (mini->argv[i][j])
		j++;
	if (j > 0 && mini->argv[i][0] == '$')
	{
		env_name = ft_substr(mini->argv[i], 1, j);
		return (env_name);
	}
	return (NULL);
}

void	echo_no_flag(t_mini *mini, int i, int j)
{
	if (i > 1)
	{
		j = 1;
		while (i > j)
		{
			if (env_flag_check(mini, j) != NULL)
				print_env_content(mini->env, env_flag_check(mini, j));
			else
				printf("%s", mini->argv[j]);
			if (i > 1 + j++)
				printf(" ");
		}
		printf("\n");
	}
}

void	echo_n_flag(t_mini *mini, int i, int j)
{
	if (i > 2)
	{
		j = 2;
		while (i > j)
		{
			if (env_flag_check(mini, j) != NULL)
				print_env_content(mini->env, env_flag_check(mini, j));
			else
				printf("%s", mini->argv[j]);
			if (i > 1 + j++)
				printf(" ");
		}
	}
}

void	ft_echo(t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mini->argv[i])
		i++;
	if (i >= 2 && str_cmp_both_len(mini->argv[1], "-n"))
		echo_n_flag(mini, i, j);
	else
		echo_no_flag(mini, i, j);
}
