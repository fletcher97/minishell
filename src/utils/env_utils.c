/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:59:39 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/20 17:04:06 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

//The Print Env Content prints the content of the provided env variable. It will
//also free the provided "name" string if we provide the char 'y' on the
//free_name param.
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

//The Return Env Content find the inputed variable name on the program internal
//environmental dual linked list and returns its content if found.
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

//The Get Name function returns the content of a string that is found before
//the provided char is found. In this case, is used to find the name of the
//variable before it find an equal sign ('=').
char	*get_name(char *str, char c)
{
	char	*name;
	int		x;

	x = -1;
	if (!str)
		return (NULL);
	name = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	while (str[++x] && str[x] != c)
		name[x] = str[x];
	name[x] = '\0';
	return (name);
}

//The Get Env function will make a copy of the system environmental list and it.
//The return is as dual linked list. Check Minishell header for the list struct.
t_dl_list	*get_env(char **env)
{
	t_dl_list	*temp;
	int			x;

	x = -1;
	g_mini.env = NULL;
	while (env[++x] != NULL)
	{
		temp = ft_lstnew_dl(ft_split(env[x], '='));
		ft_lstadd_back_dl(&g_mini.env, temp);
	}
	return (g_mini.env);
}

//The Check Env names will replace the content of the provided env variable
//'name; if found on the internal environmental list with the provided
//string 'content'.
int	check_env_names(char *name, char *content)
{
	t_dl_list	*head;

	head = g_mini.env;
	while (1)
	{
		if (ft_strcmp(name, g_mini.env->name))
		{
			free(g_mini.env->content);
			g_mini.env->content = content;
			g_mini.env = head;
			return (1);
		}
		if (g_mini.env->next == NULL)
			break ;
		g_mini.env = g_mini.env->next;
	}
	g_mini.env = head;
	return (0);
}
