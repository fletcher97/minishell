/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:21:47 by fferreir          #+#    #+#             */
/*   Updated: 2022/01/12 18:43:41 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "ft_list.h"
# include "ft_stdlib.h"
# include "ft_string.h"

# include "commands.h"
# include "execution.h"
# include "minishell.h"
# include "parser.h"

// Error codes
# define CHAR_UNHANDLED 1
# define QUOTES_OPEN 2
# define MAX_FD 256

//Error mng functions
int			error_output(char type, int i, char *str);

//Export utils functions
int			env_sorted(void);

//Env utils Functions
int			check_env_names(char *name, char *content);
void		print_env_content(t_dl_list *lst, char *name, char free_name);
char		*return_env_content(t_dl_list *lst, char *name);
char		*get_name(char *str, char c);
t_dl_list	*get_env(char **env);

//Free utils functions
void		free_list_nodes(t_dl_list *lst);
void		free_argv(void);
void		free_dl_list(t_dl_list *lst);
void		delete_temp(char *path);

//Main utils functions
void		hsi(int signal);
void		clean_processes(void);
void		re_init(void);

//Fork Functions
void		exit_fork(void);

//cmd exec
int			file_input(t_list *input, t_list *heredoc, t_list *in);
int			file_output(t_list *output, t_list *append, t_list *final_output);

//Selector functions
int			screening_one(char **argv);
void		cmd_selector(char **argv);
int			cmd_identifier(char **argv);

//Heredoc creation functions
char		*temp_path(char *filename, char *home);
void		check_heredoc(t_tree *t);

#endif
