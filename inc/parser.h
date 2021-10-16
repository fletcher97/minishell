/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:00:13 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/16 02:41:47 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_commands
{
	int		error;
	char	*cmd;
	char	**args;
	char	*input;
	char	*output;
}				t_commands;

t_commands	*parse(const char *str);

#endif
