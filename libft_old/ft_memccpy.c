/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:30:09 by fferreir          #+#    #+#             */
/*   Updated: 2021/08/23 13:57:39 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n)
	{
		((char *)dst)[x] = ((char *)src)[x];
		if (((unsigned char *)src)[x] == (unsigned char)c)
			return ((void *)&dst[x + 1]);
		x++;
	}
	return (NULL);
}
