/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:44:41 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/12 18:36:54 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

//The get signal function is used to change the behavior of each signal.
//Need to be added the ctrl+c and ctrl+d rules but the rl lib is not working.
void	get_signal(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}
