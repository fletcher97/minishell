/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:12:46 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/12 16:40:49 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PWD_H
# define PWD_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include "free_utils.h"
//# include "echo.h"

void	ft_pwd(t_dl_list *env);
void	ft_exit(void);

#endif
