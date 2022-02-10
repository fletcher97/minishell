/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:30:10 by mgueifao          #+#    #+#             */
/*   Updated: 2022/02/10 11:30:37 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

/*
*   The env function is responsible for printing the internal environ list.
*/
void	ft_env(t_dl_list *env)
{
	ft_lstprint(env, 'a');
}
