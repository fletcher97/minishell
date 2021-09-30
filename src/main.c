#include "minishell.h"



void	screening(char *input)
{
	int i;

	i = 0;
	if ((i = find_special()) == -1)
		return ;
	if (mini.argv && i == 0)
	{
		if (ft_strcmp(mini.argv[i], "pwd") || ft_strcmp(mini.argv[i], "PWD"))
			ft_pwd();
		else if (ft_strcmp(mini.argv[i], "exit"))
			ft_exit(input);
		else if (ft_strcmp(mini.argv[i], "echo"))
			ft_echo();
		else if (ft_strcmp(mini.argv[i], "cd"))
			ft_cd();
		else if (ft_strcmp(mini.argv[i], " "))
			printf("\n");
		else if(ft_strcmp(mini.argv[i], "env"))
				ft_env();
		else if(ft_strcmp(mini.argv[i], "export"))
			ft_export();
		else if(ft_strcmp(mini.argv[i], "node"))
		{
			if (ft_strlen(mini.argv[i]) > 0)
				ft_lstnode_print(mini.env, mini.argv[i + 1]);
		}
		else if (ft_strcmp(mini.argv[i], "unset"))
			ft_unset();
		else
			ft_ls(i);
	}
}

void	struct_init(char **env)
{
	mini.head = malloc(sizeof(t_list));
	mini.pid = getpid();
	mini.env = get_env(env);
	mini.exit = false;
}

int		args_counter()
{
	int i;

	i = 0;
	while (mini.argv[i])
		i++;
	return(i);
}

int main(int argc, char **argv, char **env)
{

	char	*input;
	(void) argc;
	(void) argv;

	struct_init(env);
	//signal(SIGINT , get_signal);
	//signal(SIGQUIT , get_signal);
//	while (42)
	while ((input = readline("minishell: ")))
	{
	//	input = readline("minishell: ");
	//	printf("input = %s\n", input);
		if (input && ft_strlen(input) != 0)
		{
			add_history(input);
			mini.argv = ft_split(input, ' ');
			mini.nbr_arg = args_counter();
			screening(input);
			free_argv();
			free(input);
			input = NULL;
		}
		if (mini.exit == true)
		{
			free_struct(input);
			free_lst(mini.env);
			exit(0);
		}
	}
	return (0);
}
