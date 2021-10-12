/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:36:06 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/12 15:26:58 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# include "ft_string.h"
# include "minishell.h"

void	ft_cd(char **argv);

#endif
