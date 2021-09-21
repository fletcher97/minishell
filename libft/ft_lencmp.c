#include "libft.h"

bool	ft_lencmp(char *s1, char *s2)
{
	if ((ft_strlen(s1) - ft_strlen(s2)) == 0)
		return (true);
	return(false);
}
