/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:09:10 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/14 16:20:37 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include <limits.h>
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/wait.h>
# include <unistd.h>

# include "ft_list.h"
# include "ft_stdlib.h"
# include "ft_string.h"

# include "minishell.h"
# include "utilities.h"

//CD cmd functions
void		ft_cd(char **argv);

//Echo cmd functions
void		print_env_content(t_dl_list *lst, char *name, char free_name);
char		*return_env_content(t_dl_list *lst, char *name);
void		ft_echo(char **argv);

//Env cmd functions
char		*get_name(char *str, char c);
t_dl_list	*get_env(char **env);
void		ft_env(t_dl_list *env);

//Export cmd functions
int			check_env_names(char *name, char *content);
int			ft_export(char **argv);

//Execve cmd functions
void		ft_execve(char **argv, int i);

//PWD and Exit cmd functions
void		ft_pwd(t_dl_list *env);
void		ft_exit(void);

//Signal functions
void		get_signal(int signal);

//Unset cmd functions
void		ft_unset(t_dl_list *env, char **argv, int i);

#endif
