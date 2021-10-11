/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:19:15 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/11 19:29:42 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_UTILS_H
# define FREE_UTILS_H

# include <stdio.h>
# include "ft_stdlib.h"
# include "minishell.h"

void	free_dp_list(t_dl_list *lst);
void	free_argv(void);
void	free_lst(t_dl_list *lst);
void	free_struct(char *input);

#endif
