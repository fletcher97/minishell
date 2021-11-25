/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:24:36 by fferreir          #+#    #+#             */
/*   Updated: 2021/11/25 18:59:01 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <unistd.h>

# include "commands.h"
# include "minishell.h"
# include "utilities.h"
# include "parser.h"

//Command Execution functions
void	command_exec(t_cmd *cmd);

//Pipe functions
int		first_cmd_pipe(t_cmd *cmd, int fd[2]);
int		pipe_command(t_cmd *cmd, int fd[2]);

//Simple cmd call function
int		simple_command(t_cmd *cmd);

//End cmd call function
int		end_multi_cmd(t_cmd *cmd, int fd[2]);

#endif
