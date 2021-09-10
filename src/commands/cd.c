/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:36:18 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/10 13:15:20 by falmeida         ###   ########.fr       */
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
	printf("HELLO\n");
	while (mini->argv[i] != NULL)
	{
		len += ft_strlen(mini->argv[i]);
		i++;
	}

	path = malloc(sizeof(char) * len + 1);
	i = 1;
	k = 0;
	printf("HELLO\n");
	while (mini->argv[i] != NULL)
	{
		j = 0;
		while (mini->argv[i][j])
		{
			path[k] = mini->argv[i][j++];
			printf("%c\n", path[k]);
			k++;
		}
		i++;
	}
	path[k] = '\0';
			printf("%s\n", path);

}

void	change_path(t_mini *mini, t_cd *cd)
{
	char	*str;

	get_path2(mini);
	str = NULL;
	str = getcwd(str, PATH_MAX);
	cd->tmp = mini->env;
	cd->pwd = ft_strdup(str);
	mini->env = find_name(mini->env, "OLDPWD");
	mini->env->content = ft_strdup(getcwd(cd->pwd, PATH_MAX));
	cd->path1 = get_path(mini, cd);
	cd->path2 = ft_strjoin(mini->env->content, cd->path1);
	chdir(cd->path1);
	mini->env = cd->tmp;
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

void	ft_cd_back(t_cd *cd)
{
	char	*str;

	str = NULL;
	cd->tmp = find_name(cd->tmp, "OLDPWD");
	str = getcwd(str, PATH_MAX);
	if (!ft_strncmp(str, cd->tmp->content, ft_strlen(str)))
	{

		cd->path1 = ft_substr(str, 0, len_char_back(str, '/'));
		printf("%s\n", cd->path1);
		chdir(cd->path1);
	}
	else
		chdir(cd->tmp->content);
}

void	ft_cd(t_mini *mini)
{
	t_cd	*cd;

	cd = mini->cd;
	cd->tmp = mini->env;
	if (!mini->argv[1])
	{
		cd->tmp = find_name(cd->tmp, "HOME");
		chdir(cd->tmp->content);
	}
	else if (!ft_strncmp(mini->argv[1], "..", ft_strlen(mini->argv[1])))
		ft_cd_back(cd);
	else
		change_path(mini, cd);
}
