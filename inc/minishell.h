/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:18:37 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/07 18:09:57 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdbool.h>
# include <sys/wait.h>
# include "ft_list.h"
# include "ft_string.h"
# include "ft_stdlib.h"

typedef struct s_cd
{
	t_dl_list	*tmp;
	char		*pwd;
	char		*path1;
	char		*path2;
	char		*backup;
}				t_cd;

typedef struct s_mini
{
	char		**argv;
	char		*str;
	int			pid;
	bool		exit;
	int			nbr_arg;
	t_cd		*cd;
	t_dl_list	*env;
	t_dl_list	*head;
}				t_mini;

extern t_mini	g_mini;

//error management
void		error_output(char type, int i);
//error management

//free utility
void		free_lst(t_dl_list *lst);
void		free_struct(char *input);
void		free_argv(void);
void		free_dp_list(t_dl_list *lst);
//free utility

//utility functions
void		struct_init(char **env);
int			args_counter(void);
int			find_char(char *s1, char c);
void		node_free_machine(void);
bool		lst_str_check(t_dl_list *lst, char *str);
void		sorter(t_dl_list *lst);
int			env_sorted(void);
void		sorter(t_dl_list *lst);
void		swap(t_dl_list *A, t_dl_list *B, t_dl_list *C);
bool		checker(t_dl_list *lst);
bool		check_char(char *str, char c);
int			args_counter(void);
//utility functions

//parser functions
int			resolve_special(int i, int j);
int			find_special(void);
//parset functions

//pipe functions
int			screening_pipe(int i);
int			piper(int i);
//pipe functions

//env functions
t_dl_list	*get_env(char **env);
bool		check_env_names(char *name, char *content);
void		env_add_names(t_dl_list *lst);
char		*get_name(char *str, char c);
char		*return_env_content(t_dl_list *lst, char *name);
char		*env_flag_check(int i);
void		print_env_content(t_dl_list *lst, char *name, char free_name);
//env functions

//cmd functions
void		ft_pwd(void);
void		ft_exit(char *input);
void		ft_echo(void);
void		echo_n_flag(int i, int j);
void		echo_no_flag(int i, int j);
void		ft_cd(void);
void		ft_ls(int i);
void		ft_env(void);
int			ft_export(void);
void		ft_unset(void);
//cmd functions

//signal functions
void		get_signal(int signal);
//signal functions

#endif
