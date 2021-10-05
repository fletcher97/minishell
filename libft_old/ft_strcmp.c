#include "libft.h"

bool	ft_strcmp(char *s1, char *s2)
{
	if (!ft_lencmp(s1, s2))
		return (false);
	if (!(ft_strncmp(s1,s2, ft_strlen(s1))))
	{
		if (!(ft_strncmp(s1,s2, ft_strlen(s2))))
			return (true);
	}
	return (false);
}
