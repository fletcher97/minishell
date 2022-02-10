/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:18:37 by mgueifao          #+#    #+#             */
/*   Updated: 2022/02/10 17:20:42 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ft_list.h"

# include "parser.h"

# define FD_MAX 256

# ifndef CHILD_MAX
#  define CHILD_MAX 512
# endif

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
	int			skip;
	int			error;
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
	int			pid;
	int			*pid_lst;
	t_cd		*cd;
	t_commands	*cmd;
	t_dl_list	*env;
	t_dl_list	*head;
}				t_mini;

extern t_mini	g_mini;

#endif
