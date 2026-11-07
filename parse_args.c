#include "push_swap.h"

void	config_init(t_config *cfg)
{
	cfg->strategy = STRAT_ADAPTIVE;
	cfg->bench = 0;
	cfg->values = NULL;
	cfg->count = 0;
}

int	add_number(t_stack *a, int value)
{
	t_node	*node;

	if (check_duplicates(a, value))
		return (0);
	node = stack_new_node(value);
	if (!node)
		return (0);
	list_add_back(a, node);
	return (1);
}

void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	handle_arg(char *arg, t_stack *a, t_config *cfg)
{
	char	**args;
	int		value;
	int		i;
	int		ok;

	args = ft_split(arg, ' ');
	if (!args || !args[0])
	{
		free_split(args);
		return (0);
	}
	ok = 1;
	i = 0;
	while (ok && args[i])
	{
		if (!parse_flag(args[i], cfg))
			ok = parse_number(args[i], &value) && add_number(a, value);
		i++;
	}
	free_split(args);
	return (ok);
}

int	parse_args(int argc, char **argv, t_stack *a, t_config *cfg)
{
	int	i;

	config_init(cfg);
	i = 1;
	while (i < argc)
	{
		if (!handle_arg(argv[i], a, cfg))
		{
			stack_free(a);
			return (0);
		}
		i++;
	}
	return (1);
}
