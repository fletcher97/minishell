/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:19:15 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/12 17:27:11 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_UTILS_H
# define FREE_UTILS_H

# include <stdio.h>
# include "ft_stdlib.h"
# include "minishell.h"

void	free_list_nodes(t_dl_list *lst);
void	free_argv(void);
void	free_dl_list(t_dl_list *lst);

#endif
