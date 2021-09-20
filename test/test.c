#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (n == 0)
		return (0);
	while (s1[x] == s2[x] && s1[x] && s2[x] && x < (n - 1))
		x++;
	return ((unsigned char)(s1[x]) - (unsigned char)(s2[x]));
}

int main(int argc, char **argv)
{
	int ret;

	if (argc != 3)
		return(0);
	ret = ft_strncmp(argv[1], argv[2], strlen(argv[1]));
	printf("%d\n", ret);
	return(0);
}
