/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:09:01 by fferreir          #+#    #+#             */
/*   Updated: 2022/02/10 10:42:42 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

#include "readline.h"

#include "ft_stdlib.h"
#include "ft_string.h"

#include "minishell.h"
#include "utilities.h"

/*
*   Sets up the behaviour for the signal when pressing ctr+c.
*/
void	hsi(int signal)
{
	rl_replace_line("", signal);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

/*
*   It will re-initialize all the variables that are needed to be reseted for
*    the input loop. It will also call the Clean Processes function.
*/
void	re_init(void)
{
	clean_processes();
	g_mini.fd_in = 0;
	g_mini.fd_out = 1;
	g_mini.cmd_counter = 0;
	g_mini.file_counter = 0;
	g_mini.hdoc_counter = 0;
	g_mini.pid_counter = -1;
	g_mini.first_cmd = 1;
	g_mini.skip = 0;
}

/*
*   Struct init function is used to initiate the stuct variable and cut down
*    some lines in the main function body.
*/
void	struct_init(char **env)
{
	g_mini.head = ft_malloc(sizeof(t_dl_list));
	g_mini.env = get_env(env);
	g_mini.exit = 0;
	g_mini.exit_status = 0;
	g_mini.skip = 0;
	g_mini.fd_in = 0;
	g_mini.fd_out = 1;
	g_mini.hdoc_counter = 0;
	g_mini.temp_path = ft_strdup("/tmp/");
	create_hdoc_and_pid_arrays();
	g_mini.file_counter = 0;
	g_mini.cmd_counter = 0;
	g_mini.pid_counter = -1;
}

/*
*   Used mainly to save lines. It will create both temp FDs that are a dup from
*    from 1 and 0 to be used throught the child loops on the tree_loop function
*    on the main file.
*/
int	dup_init_and_close(char type)
{
	if (type == 'i')
	{
		g_mini.tmp_in = dup(0);
		g_mini.tmp_out = dup(1);
		g_mini.fd_in = dup(g_mini.tmp_in);
	}
	if (type == 'c')
	{
		dup2(g_mini.tmp_in, 0);
		dup2(g_mini.tmp_out, 1);
		close(g_mini.tmp_in);
		close(g_mini.tmp_out);
	}
	return (0);
}
