#include "minishell.h"

int	resolve_special(int i, int j)
{
	(void) j;
	if (i == 0)
		error_output('s', i);
//		redirect_output(i, j);
	else if (i == 1)
		error_output('s', i);
//		redirect_input(i, j);
	else if (i == 2)
		error_output('s', i);
//		read_input_from(i, j);
	else if (i == 3)
		error_output('s', i);
//		append_output(i ,j);
	else if (i == 4)
		error_output('s', i);
//		pipe_output(i, j);
	else
		error_output('s', i);
	return(i);
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
				i = resolve_special(i, j);
		}
	}
	return(1);
}
