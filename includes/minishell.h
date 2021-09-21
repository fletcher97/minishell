#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include <signal.h>
#include <stdbool.h>

typedef struct	s_cd {

	t_list	*tmp;
	char	*pwd;
	char	*path1;
	char	*path2;
	char	*backup;
} t_cd;

typedef struct	s_mini {
	char	**argv;
	char	*str;
	int		pid;
	bool	exit;
	t_cd	*cd;
	t_list	*env;
	t_list	*head;
} t_mini;

//error management
void	error_output(t_mini *mini, char type);
//error management

//free utility
void	free_lst(t_list *lst);
void	free_struct(t_mini *mini, char *input);
void	free_argv(t_mini *mini);
void	free_dp_list(t_list *lst);
//free utility

//utility functions
int		find_char(char *s1, char c);
void	node_free_machine(t_mini *mini);
void	ft_lstnode_print(t_list *lst, char *name);
t_list	*ft_lstnew_pp(char **content);
bool	lst_str_check(t_list *lst, char *str);
bool	str_len_check(char *s1, char *s2);
bool	str_cmp_both_len(char *s1, char *s2);
void	sorter(t_list *lst);
int		env_sorted(t_mini *mini);
void	sorter(t_list *lst);
void	swap(t_list *A, t_list *B, t_list *C);
bool	checker(t_list *lst);
//utility functions

//env functions
t_list	*get_env(char **env, t_mini *mini);
bool	check_env_names(t_mini *mini, char *name, char *content);
void	env_add_names(t_list *lst);
char	*get_name(char *str, char c);
char	*return_env_content(t_list *lst, char *name);
char	*env_flag_check(t_mini *mini, int i);
//env functions

//commands.c
void	ft_pwd(void);
void	ft_exit(t_mini *mini, char *input);
void	ft_echo(t_mini *mini);
void	echo_n_flag(t_mini *mini, int i, int j);
void	echo_no_flag(t_mini *mini, int i, int j);
void	ft_cd(t_mini *mini);
void	ft_ls(t_mini *mini);
void	ft_env(t_mini *mini);
int		ft_export(t_mini *mini);
void	ft_unset(t_mini *mini);
//commands.c

void	get_signal(int signal);

//main.c
char    *pwd(void);
//main.c

#endif
