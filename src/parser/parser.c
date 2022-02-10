/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:03:59 by mgueifao          #+#    #+#             */
/*   Updated: 2022/02/10 04:59:54 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdlib.h>

#include "ft_string.h"
#include "ft_stdlib.h"

#include "parser.h"
#include "utilities.h"

static void	free_cmd(void *v)
{
	t_cmd	*cmd;
	int		i;

	if (!v)
		return ;
	cmd = (t_cmd *)v;
	if (cmd->line)
		ft_free(cmd->line);
	i = -1;
	if (cmd->cmd)
	{
		while (cmd->cmd[++i])
			ft_free(cmd->cmd[i]);
		ft_free(cmd->cmd);
	}
	if (cmd->in.input)
		ft_lstclear(&cmd->in.input, ft_free);
	if (cmd->in.heredoc)
		ft_lstclear(&cmd->in.heredoc, ft_free);
	if (cmd->in.output)
		ft_lstclear(&cmd->in.output, ft_free);
	if (cmd->in.append)
		ft_lstclear(&cmd->in.append, ft_free);
	ft_free(v);
}

void	free_command(t_commands *cmd)
{
	ft_free(cmd->line);
	ft_treeclear(cmd->tree, free_cmd);
	ft_free(cmd);
}

void	squash_r(t_tree *t)
{
	int	i;

	if (!t->lcount)
		return ;
	i = -1;
	while (++i < t->lcount)
	{
		if (t->leafs[i]->lcount)
		{
			squash_r(t->leafs[i]);
			if (i + 1 < t->lcount)
			{
				if (!t->leafs[i]->content)
					t->leafs[i]->content = ft_calloc(1, sizeof(t_cmd));
				((t_cmd *)t->leafs[i]->content)->cmd_flags
					= ((t_cmd *)t->leafs[i + 1]->content)->cmd_flags;
			}
		}
	}
}

t_commands	*squash(t_commands *cmd)
{
	squash_r(cmd->tree);
	return (cmd);
}

t_commands	*parse(const char *str)
{
	t_commands	*cmd;

	cmd = validate(str);
	if (!cmd || cmd->error)
		return (cmd);
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
	if (!word_split(cmd->tree))
		cmd->error = 10000;
	if (!cmd->error)
		unmask(cmd->tree);
	return (squash(cmd));
}
