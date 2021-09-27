#include "minishell.h"

void	get_signal(int signal)
{
	//signal == SIGQUIT
	if (signal == SIGINT)
	{
		write(1,"\n", 1);
		//rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}
