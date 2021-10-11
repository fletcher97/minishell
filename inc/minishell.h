/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:18:37 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/11 19:24:17 by fferreir         ###   ########.fr       */
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

# include "pwd.h"
# include "echo.h"
# include "cd.h"
# include "env.h"
# include "export.h"
# include "unset.h"
# include "ls.h"
# include "parser.h"
# include "free_utils.h"
# include "main_utils.h"

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
	int			exit;
	int			nbr_arg;
	t_cd		*cd;
	t_dl_list	*env;
	t_dl_list	*head;
}				t_mini;

extern t_mini	g_mini;

#endif
