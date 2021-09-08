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

typedef struct	s_mini {
	char	**argv;
	char	*str;
	int		pid;
	t_list	*env;
} t_mini;

//utility functions
void	node_free_machine(t_mini *mini);
void	ft_lstnode_print(t_list *lst, char *name);
t_list	*get_env(char **env, t_mini *mini);
char	*get_name(char *str, char c);
void	env_add_names(t_list *lst);
bool	check_env_names(t_mini *mini, char *name);
bool	lst_str_check(t_list *lst, char *str);
bool	str_len_check(char *s1, char *s2);
bool	str_cmp_both_len(char *s1, char *s2);
//utility functions


//commands.c
void	ft_pwd(void);
void	ft_exit(int pid);
void	ft_echo(char **argv);
void	ft_cd(t_mini *mini);
void	ft_ls(t_mini *mini);
void	ft_env(t_mini *mini);
void	ft_export(t_mini *mini);
void	ft_unset(t_mini *mini);
//commands.c

//main.c
char    *pwd(void);
//main.c

#endif
