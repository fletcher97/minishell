/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:08:11 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/12 16:16:08 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSET_H
# define UNSET_H

# include "ft_stdlib.h"
# include "ft_string.h"
# include "minishell.h"

void	ft_unset(t_dl_list *env, char **argv, int i);

#endif
