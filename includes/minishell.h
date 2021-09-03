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
} t_mini;

//commands.c
void	ft_pwd(void);
void	ft_exit(int pid);
void	ft_echo(t_mini *mini);
void	ft_cd(void);
//commands.c

//main.c
char    *pwd(void);
//main.c

#endif
