/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:18:37 by mgueifao          #+#    #+#             */
/*   Updated: 2022/02/07 22:02:58 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "ft_stdlib.h"
# include "ft_string.h"
# include "ft_list.h"
# include "ft_conv.h"

# include "commands.h"
# include "utilities.h"
# include "parser.h"
# include "execution.h"

# define FD_MAX 256
# define CHILD_MAX 512
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
	char		*temp_path;
	int			exit;
	int			nbr_arg;
	int			exit_status;
	int			first_cmd;
	int			fd[2];
	int			tmp_in;
	int			tmp_out;
	int			fd_in;
	int			fd_out;
	char		*input;
	char		*heredoc;
	char		**hdoc_files;
	int			cmd_counter;
	int			file_counter;
	int			hdoc_counter;
	int			pid_counter;
	int			and_flag;
	int			or_flag;
	int			es_flag;
	int			pid;
	int			*pid_lst;
	int			stop;
	int			saved_fd;
	int			cancel;
	t_cd		*cd;
	t_commands	*cmd;
	t_dl_list	*env;
	t_dl_list	*head;
}				t_mini;

extern t_mini	g_mini;

#endif
