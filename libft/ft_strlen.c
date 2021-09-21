/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:27:31 by fferreir          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/09/20 13:25:24 by fferreir         ###   ########.fr       */
=======
/*   Updated: 2021/09/20 11:57:51 by falmeida         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	x;
<<<<<<< HEAD

	if (!str)
		return(0);
=======
	if (!str)
		return (0);
>>>>>>> main
	x = 0;
	while (str[x])
		x++;
	return (x);
}
