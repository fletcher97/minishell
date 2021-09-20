/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:36:18 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/14 16:24:04 by falmeida         ###   ########.fr       */
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

char	*get_path(t_mini *mini, t_cd *cd)
{
	char	*path;
	int		i;

	i = 1;
	path = ft_strjoin("/", mini->argv[i]);
	while (mini->argv[i + 1] != NULL)
	{
		path = ft_strjoin(path , " ");
		path = ft_strjoin(path , mini->argv[i + 1]);
		i++;
	}
	path = ft_strjoin(cd->pwd , path);
	return (path);
}

void	get_path2(t_mini *mini)
{
	char	*path;
	int		len;
	int		i;
	int		j;
	int		k;

	i = 1;
	len = 0;
	while (mini->argv[i] != NULL)
	{
		len += ft_strlen(mini->argv[i]);
		i++;
	}

	path = malloc(sizeof(char) * len + 1);
	i = 1;
	k = 0;
	while (mini->argv[i] != NULL)
	{
		j = 0;
		while (mini->argv[i][j])
		{
			path[k] = mini->argv[i][j++];
			//printf("%c\n", path[k]);
			k++;
		}
		i++;
	}
	path[k] = '\0';
}

void	change_path(t_mini *mini, t_cd *cd)
{
	char	*str;

	get_path2(mini);
	str = NULL;
	str = getcwd(str, PATH_MAX);
	cd->tmp = mini->env;
	cd->pwd = ft_strdup(str);
	cd->path1 = get_path(mini, cd);
	chdir(cd->path1);
	check_env_names(mini, "PWD", cd->path1);
	check_env_names(mini, "OLDPWD", cd->pwd);
	mini->env = mini->head;
}

int	len_char_back(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while ((str[i] != c))
		i--;
	return (i);
}

void	ft_cd_back(t_mini *mini, t_cd *cd)
{
	char	*str;
	char	*old_pwd;
	str = NULL;
	mini->head = mini->env;

	cd->backup = return_env_content(cd->tmp, "OLDPWD");
	str = getcwd(str, PATH_MAX);
	old_pwd = str;
	if (!ft_strncmp(str, cd->backup, str_cmp_both_len(str, cd->backup)))
	{
		cd->path1 = ft_substr(str, 0, len_char_back(str, '/'));
		chdir(cd->path1);
		check_env_names(mini, "PWD", cd->path1);
		check_env_names(mini, "OLDPWD", old_pwd);
	}
	else
	{
		chdir(cd->tmp->content);
	}
	mini->env = mini->head;
}

void	ft_cd(t_mini *mini)
{
	t_cd	cd;
	char	*str;
	char	*home;

	home = NULL;
	str = NULL;
	mini->head = mini->env;
	cd.tmp = mini->env;
	home = getcwd(home, PATH_MAX);
	if (!mini->argv[1])
	{
		mini->cd->backup = return_env_content(mini->env, "PWD");
		str = return_env_content(mini->env, "HOME");
		chdir(str);
		check_env_names(mini , "PWD", str);
		mini->env = mini->head;
		check_env_names(mini , "OLDPWD", home);
		mini->env = mini->head;

	}
	else if (!ft_strncmp(mini->argv[1], "..", ft_strlen(mini->argv[1])))
		ft_cd_back(mini, &cd);
	else
		change_path(mini, &cd);
}
