/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_mng.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:26:14 by fferreir          #+#    #+#             */
/*   Updated: 2021/12/07 15:02:19 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

//The Temp Path function is responsible to create the path for the temporary
//files that hold the heredoc data provided by the user.
char	*temp_path(char *filename, char *path)
{
	char	*pth;

	if (!filename || !path)
		return (NULL);
	pth = ft_strjoin(path, filename);
	g_mini.hdoc_files[g_mini.file_counter++] = filename;
	return (pth);
}

//The create heredoc file function is to create and save the information
//provided by the user through input. The temp file name is going to be a
//joint of the eof provided by the user and a global counter used for heredoc
//requests count.
static int	create_hrdoc_file(char *eof_str, char *filename)
{
	char	*input;
	int		output;

	if (!eof_str)
		return (-1);
	filename = temp_path(filename, g_mini.temp_path);
	if (!filename)
		return (-1);
	output = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IROTH);
	if (output < 0)
		return (-1);
	input = readline("> ");
	while (ft_strcmp(input, eof_str) != 1)
	{
		if (ft_strlen(input) > 0)
			write(output, input, ft_strlen(input));
		write(output, "\n", 2);
		input = readline("> ");
	}
	free(eof_str);
	free(filename);
	close(output);
	return (0);
}

//The Check heredoc call function will look for a heredoc call on the provided
//cmd line. If found, it will request the creation of a temporary file that will
//would the heredoc data.
static void	check_heredoc_call(t_cmd *cmd)
{
	char	*filename;
	char	*eof;
	t_list	*head;

	eof = NULL;
	if (cmd->in.heredoc)
		head = cmd->in.heredoc;
	while (cmd->in.heredoc)
	{
		eof = (char *)cmd->in.heredoc->content;
		filename = ft_strjoin(eof, ft_itoa(++g_mini.hdoc_counter));
		if (create_hrdoc_file(ft_substr(eof, 2, ft_strlen(eof)), filename) < 0)
			printf("Error: unable to create heredoc file\n");
		cmd->in.heredoc = cmd->in.heredoc->next;
	}
	if (eof)
		cmd->in.heredoc = head;
}

//The Check heredoc function is to run through the command list. If cmd does not
//point to NULL, it will send it to another function to check for an eventual
//heredoc call in the cmd line.
void	check_heredoc(t_tree *t)
{
	t_cmd		*cmd;
	static int	step;
	int			i;

	cmd = (t_cmd *)t->content;
	step += 10;
	i = -1;
	if (cmd)
	{
		g_mini.hdoc_counter = step;
		check_heredoc_call(cmd);
	}
	else
		while (++i < t->lcount)
			check_heredoc(t->leafs[i]);
}