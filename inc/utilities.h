/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:21:47 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/14 16:22:49 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include <stdio.h>
# include <stdlib.h>

# include "ft_list.h"
# include "ft_stdlib.h"
# include "ft_string.h"

# include "commands.h"
# include "minishell.h"

//Error mng functions
void	error_output(char type, int i);

//Export utils functions
int		env_sorted(void);

//Free utils functions
void	free_list_nodes(t_dl_list *lst);
void	free_argv(void);
void	free_dl_list(t_dl_list *lst);

//Main utils functions
int		args_counter(void);

//Parser functions
int		find_special(void);

//Piper functions
int		piper(int i);

#endif
