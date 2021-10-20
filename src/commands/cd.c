/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:29:42 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/20 18:53:52 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static char	*get_path(t_cd *cd)
{
	char	*path;
	int		i;

	i = 1;
	path = ft_strjoin("/", g_mini.argv[i]);
	while (g_mini.argv[i + 1] != NULL)
	{
		path = ft_strjoin(path, " ");
		path = ft_strjoin(path, g_mini.argv[i + 1]);
		i++;
	}
	path = ft_strjoin(cd->pwd, path);
	return (path);
}

static void	change_path(t_cd *cd)
{
	char	*str;
	int		i;

	str = NULL;
	str = getcwd(str, PATH_MAX);
	cd->tmp = g_mini.env;
	cd->pwd = ft_strdup(str);
	cd->path1 = get_path(cd);
	i = chdir(cd->path1);
	printf("|%d|\n", i);
	check_env_names("PWD", cd->path1);
	check_env_names("OLDPWD", cd->pwd);
	g_mini.env = g_mini.head;
}

static int	len_char_back(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while ((str[i] != c))
		i--;
	return (i);
}

static void	ft_cd_back(t_cd *cd)
{
	char	*str;
	char	*old_pwd;

	str = NULL;
	g_mini.head = g_mini.env;
	cd->backup = return_env_content(cd->tmp, "OLDPWD");
	str = getcwd(str, PATH_MAX);
	old_pwd = str;
	if (!ft_strcmp(str, cd->backup))
	{
		cd->path1 = ft_substr(str, 0, len_char_back(str, '/'));
		chdir(cd->path1);
		check_env_names("PWD", cd->path1);
		check_env_names("OLDPWD", old_pwd);
	}
	else
	{
		if (!(chdir(cd->tmp->content)))
			printf("cd: no such file or directory: %s\n", \
				(char *)cd->tmp->content);
	}
	g_mini.env = g_mini.head;
}

void	ft_cd(char **argv)
{
	t_cd	cd;
	char	*str;
	char	*home;
	int		i;

	home = NULL;
	str = NULL;
	g_mini.head = g_mini.env;
	cd.tmp = g_mini.env;
	home = getcwd(home, PATH_MAX);
	i = 0;
	if (!argv[1])
	{
		str = return_env_content(g_mini.env, "HOME");
		chdir(str);
		check_env_names("PWD", str);
		check_env_names("OLDPWD", home);
	}
	else if (ft_strcmp(argv[1], ".."))
		ft_cd_back(&cd);
	else
		change_path(&cd);
}
