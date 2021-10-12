/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:36:10 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/12 15:44:36 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# include "ft_stdlib.h"
# include "ft_list.h"
# include "ft_string.h"

# include "export_utils.h"
# include "env.h"

int	check_env_names(char *name, char *content);
int	ft_export(char **argv);

#endif
