/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:18:37 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/07 15:07:08 by fferreir         ###   ########.fr       */
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
	int			pid;
	int			exit;
	int			nbr_arg;
	int			errno;
	int			exit_status;
	int			first_cmd;
	int			fd[2];
	int			saved_fd;
	char		*input;
	char		*heredoc;
	char		**hdoc_files;
	int			hdoc_counter;
	int			file_counter;
	t_cd		*cd;
	t_commands	*cmd;
	t_dl_list	*env;
	t_dl_list	*head;
}				t_mini;

extern t_mini	g_mini;

#endif
