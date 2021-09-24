#include "minishell.h"

int	resolve_special(int i, int j)
{
	if (j == 0)
		error_output('s', i);
//		redirect_output(i, j);
	else if (j == 1)
		error_output('s', i);
//		redirect_input(i, j);
	else if (j == 2)
		error_output('s', i);
//		read_input_from(i, j);
	else if (j == 3)
		error_output('s', i);
//		append_output(i ,j);
	else if (j == 4 && i != 0)
//		error_output('s', i);
		piper(i);
	else
		error_output('s', i);
	return(0);
}

int	find_special(void)
{
	char	special[12][2] = {"<", ">", "<<", ">>", "|", ";", "&", "?", "*", "\\", "#", "$"};
	int		i;
	int		j;

	i = -1;
	while(mini.argv[++i])
	{
		j = -1;
		while (++j < 12 )
		{
			if (ft_strcmp(mini.argv[i], special[j]))
			{
				i = resolve_special(i, j);
				return(-1);
			}
		}
	}
	return(0);
}
