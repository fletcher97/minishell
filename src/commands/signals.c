/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:44:41 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/11 18:44:44 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

// first instruction:	signal == SIGQUIT
// after write:			rl_replace_line("", 0);
void	get_signal(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}
