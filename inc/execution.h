/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:24:36 by fferreir          #+#    #+#             */
/*   Updated: 2022/02/09 02:29:20 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "parser.h"

/*
*   Command Execution functions
*/
int		command_exec(t_cmd *cmd);
/*
*   Pipe functions
*/
int		pipe_command(t_cmd *cmd, int fd[2]);

/*
*execute cmd function
*/
int		execute_cmd(t_cmd *cmd);

/*
*   Execute bultin functions
*/
int		bultin_exec(t_cmd *cmd);
#endif
