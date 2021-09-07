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

typedef struct	s_mini {
	char	**argv;
	char	*str;
	int		pid;
	t_list	*env;
} t_mini;

//utility functions
t_list	*get_env(char **env, t_mini *mini);
char	*get_name(t_list *lst, char c);
void	env_add_names(t_list *lst);
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
