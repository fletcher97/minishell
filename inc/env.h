/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:05:39 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/11 19:30:18 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdlib.h>
# include "ft_string.h"
# include "minishell.h"

char		*get_name(char *str, char c);
t_dl_list	*get_env(char **env);
void		ft_env(void);

#endif
