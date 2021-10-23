/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:00:13 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/16 20:23:28 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ft_tree.h"
# include "ft_list.h"

/**
 * error: Error code if parser fails
 */
typedef struct s_commands
{
	int		error;
	char	*line;
	t_tree	tree;
}				t_commands;

/**
 * in: pointer to the actual input node
 * input: Input for command if any. NULL for stdin otherwise contains path to
 *   file. If heredoc the end string is specified here
 * input_flags: Flags for input.
 *   Defaults to 0. No extract info
 *   If (input_flags & 1) heredoc used as input.
 *   If (input_flags & 2) input piped from previous cmd.
 * output: Input for command if any. NULL for stdout otherwise contains path to
 *   file.
 * output_flags: Flags for output. Defaults to 0. Set to 1 if file in append.
 */
typedef struct s_input
{
	t_list	*in;
	t_list	*input;
	t_list	*heredoc;
	t_list	*out;
	t_list	*output;
}				t_input;

/**
 * cmd: Command to be executed
 * cmd_flags: flags about the command.
 *   If (cmd_flags & 1) at least one argument/cmd has a possible wildcard.
 *   If (cmd_flags & 2) at least one argument/cmd needs to expand exit code.
 * args: Arguments to be passed to the command
 * in: input
 */
typedef struct s_cmd
{
	char	*line;
	char	*cmd;
	char	cmd_flags;
	t_list	*args;
	t_input in;
}				t_cmd;

t_commands	*parse(const char *str);
void		split_cmd(const char *str, t_commands *cmd);
void		parse_op(const char *str, t_commands *cmd);
char		*expand(char *s, t_cmd *cmd);
void		free_cmd(t_commands *cmd);

#endif
