/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:00:13 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/16 18:51:34 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/**
 * error: Error code if parser fails
 * cmd: Command to be executed
 * cmd_flags: flags about the command.
 *   If (cmd_flags & 1) at least one argument/cmd has a possible wildcard.
 *   If (cmd_flags & 2) at least one argument/cmd needs to expand exit code.
 * args: Arguments to be passed to the command
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
typedef struct s_commands
{
	int					error;
	char				*line;
	char				*cmd;
	char				cmd_flags;
	char				**args;
	char				*input;
	char				input_flags;
	char				*output;
	char				output_flags;
}				t_commands;

t_commands	*parse(const char *str);
void		split_cmd(const char *str, t_commands *cmd);
void		parse_op(const char *str, t_commands *cmd);
char		*expand(char *s, t_commands *cmd);
void		free_cmd(t_commands *cmd);

#endif
