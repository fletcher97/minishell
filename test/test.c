#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef struct s_cmd
{
	char *cmd;
	char **flags;
	char *separator;
	t_cmd *next;
} t_cmd;

static char	special[12][2] = {"<", ">", "<<", ">>", "|", ";", "&", "?", "*", "\\", "#", "$"};

int	ft_strlen(char *str)
{
	int x = 0;

	while (str)
		x++;
	return(x);
}

bool is_special(char c)
{
	int i;

	i = -1;
	while(special[++i])
	{
		if (c == special[x])
			return(true);
	}
		return(false);
}

char **cmd_args(char *str)
{
	int i;
	int j;
	char **cmd_table;
	char *temp;

	i = -1;
	temp = malloc(sizeof(char) + ft_strlen(str + 1));
	while (str[++i])
	{
		if (is_special(char c);
		{
			temp[j] = '\0';
			cmd_table[j] = temp;
		}
		else if (is_space(char c))
		{
			temp[j] = '\0';
			cmd_table[j] = temp;
		}
		else
			temp[j] = str[i];
	}
}

int main(int argc, char **argv)
{
	char **cmd_array;
	char *args;
	int ret;
	int x;

	if (argc != 3)
		return(0);
	args = stdup("");
	x = -1;
	while(++x <= argc)
		args = strjoin(args, argv[x]);
	cmd_array = cmd_args(args);
	printf("%d\n", ret);
	return(0);
}
