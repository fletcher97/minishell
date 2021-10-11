/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:42:27 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/11 19:30:47 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <unistd.h>

void	get_signal(int signal);

#endif
