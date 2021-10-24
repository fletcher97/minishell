/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:03:59 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/24 07:49:19 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include "parser.h"
#include "utilities.h"

static void	free_cmd(void *v)
{
	t_cmd	*cmd;

	if (!v)
		return ;
	cmd = (t_cmd *)v;
	if (cmd->line)
		free(cmd->line);
	if (cmd->args)
		ft_lstclear(&cmd->args, free);
	if (cmd->in.input)
		ft_lstclear(&cmd->in.input, free);
	if (cmd->in.heredoc)
		ft_lstclear(&cmd->in.heredoc, free);
	if (cmd->in.output)
		ft_lstclear(&cmd->in.output, free);
	if (cmd->in.append)
		ft_lstclear(&cmd->in.append, free);
	ft_free(v);
}

void	free_command(t_commands *cmd)
{
	free(cmd->line);
	ft_treeclear(cmd->tree, free_cmd);
}

t_commands	*parse(const char *str)
{
	t_commands	*cmd;

	cmd = calloc(1, sizeof(t_commands));
	cmd->tree = ft_treenew(NULL);
	cmd->line = proc_q(ft_strdup(str), cmd);
	if ((split_cmd(cmd->tree, cmd->line, 0) - 1) == (int)ft_strlen(cmd->line))
		if (!cmd->error)
			cmd->error = 10;
	if (cmd->error)
		return (cmd);
	if (!parse_op(cmd->tree))
		cmd->error = 100;
	if (cmd->error)
		return (cmd);
	if (!expand(cmd->tree))
		cmd->error = 1000;
	if (cmd->error)
		return (cmd);
	return (cmd);
}
// Missing
// word_splitting(str, cmd);
