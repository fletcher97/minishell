/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:09:01 by fferreir          #+#    #+#             */
/*   Updated: 2021/10/14 16:14:37 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

//The args counter function is to count the number of arguments created by the
//received by the user input and stored on an array by the split function.
//This function is not being used right now.
int	args_counter(void)
{
	int	i;

	i = 0;
	while (g_mini.argv[i])
		i++;
	return (i);
}
