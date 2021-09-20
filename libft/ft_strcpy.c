/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:45:11 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/10 20:17:17 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_strcpy(char *src, char *dst)
{
	int	x;

	x = 0;
	while (str[x])
	{
		dst[x] = str[x];
		x++;
	}
	dst[x] = '\0';
	return(dst);
}
