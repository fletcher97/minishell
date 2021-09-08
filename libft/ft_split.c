/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fferreir <fferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:57:48 by fferreir          #+#    #+#             */
/*   Updated: 2021/09/08 18:09:44 by fferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_splits(char *s, char c)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (s[x])
	{
		while (s[x] && s[x] == c)
			x++;
		if (!s[x])
			break ;
		while (s[x] && s[x] != c)
			x++;
		count++;
	}
	return (count);
}

static int	sub_len(char *s, char c, int x)
{
	int	count;

	count = 0;
	while (s[x] && s[x] != c)
	{
		count++;
		x++;
	}
	return (count);
}

static char	**split_func(char **split, char *s, char c)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	while (s[x])
	{
		z = 0;
		while (s[x] && s[x] == c)
			x++;
		if (s[x] && s[x] != c)
		{
			split[y] = (char *)ft_calloc((sub_len(s, c, x) + 1), sizeof(char));
			while (s[x] && s[x] != c)
			{
				split[y][z] = s[x++];
				z++;
			}
			split[y][z] = '\0';
			y++;
		}
	}
	split[y] = 0;
	return (split);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	char	*str;
	int		splits;

	if (!s || c < 0 || c > 127)
		return (NULL);
	if (!ft_strrchr(s, c))
	{
		split = (char **)malloc(sizeof(char *) * 2);
		split[0] = ft_strdup(s);
		split[1] = NULL;
		return (split);
	}
	str = (char *)s;
	splits = count_splits((char *)s, c);
	split = (char **)ft_calloc((splits + 1), sizeof(char *));
	if (!split)
		return (NULL);
	split_func(split, str, c);
	return (split);
}
