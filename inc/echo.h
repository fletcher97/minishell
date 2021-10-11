/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:02:06 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/11 18:05:06 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H

# include <stdio.h>
# include "ft_string.h"
# include "minishell.h"

void	print_env_content(t_dl_list *lst, char *name, char free_name);
char	*return_env_content(t_dl_list *lst, char *name);
void	ft_echo(void);

#endif
