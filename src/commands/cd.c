/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:36:18 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/09 18:19:26 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*find_name(t_list *lst, char *str)
{
	while (lst)
	{
		if (str_cmp_both_len(lst->name, str))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	change_path(t_mini *mini)
{
	char	*str;
	//char	*path;
	char	*backup;
	t_list	*tmp;
	str = NULL;
	tmp = mini->env;
	backup = ft_strdup(getcwd(str, PATH_MAX));
	mini->env = find_name(mini->env, "OLDPWD");
	mini->env->content = ft_strdup(getcwd(str, PATH_MAX));
	mini->env = tmp;
}

void	ft_cd(t_mini *mini)
{
	t_list *tmp;

	tmp = mini->env;
	if (!mini->argv[1])
	{
		tmp = find_name(tmp, "HOME");
		chdir(tmp->content);
	}
	else
		change_path(mini);
}
