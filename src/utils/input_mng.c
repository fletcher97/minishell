/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:00:03 by fferreir          #+#    #+#             */
/*   Updated: 2021/12/27 17:59:21 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

static int	heredoc_loop(t_list *heredoc, int input_hdoc)
{
	char	*pth;

	while (heredoc)
	{
		if (input_hdoc)
			close(input_hdoc);
		pth = ft_strjoin((char *)heredoc->content,
				ft_itoa(++g_mini.hdoc_counter));
		pth = temp_path(pth, g_mini.temp_path);
		input_hdoc = open(pth, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		heredoc = heredoc->next;
		free(pth);
	}
	return (input_hdoc);
}

static int	input_loop(t_list *input, int input_file)
{
	char	*pth;

	while (input)
	{
		if (input_file)
			close(input_file);
		pth = ft_substr((char *)input->content, 1,
				ft_strlen((char *)input->content));
		input_file = open(pth, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		input = input->next;
		free(pth);
	}
	return (input_file);
}

int	file_input(t_list *input, t_list *heredoc, t_list *in)
{
	int		input_file;
	int		input_hdoc;

	input_file = 0;
	input_hdoc = 0;
	input_file = input_loop(input, input_file);
	input_hdoc = heredoc_loop(heredoc, input_hdoc);
	if (!ft_strncmp(in->content, "<<", 2))
	{
		if (input_file)
			close(input_file);
		return (input_hdoc);
	}
	if (input_hdoc)
		close(input_hdoc);
	return (input_file);
}
