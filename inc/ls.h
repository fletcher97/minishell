/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:08:55 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/12 15:58:28 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>

# include "ft_string.h"

# include "error_mng.h"
# include "minishell.h"

void	ft_ls(int i);

#endif
