#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	x;

	if (!str)
		return(0);
	x = 0;
	while (str[x])
		x++;
	return (x);
}
