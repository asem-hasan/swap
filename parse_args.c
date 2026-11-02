/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:04:27 by syaseen           #+#    #+#             */
/*   Updated: 2026/10/28 15:08:01 by syaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

void	free_split(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	handle_arg(char *arg, t_stack *a, t_config *cfg)
{
	char	**tokens;
	int		value;
	int		i;
	int		ok;

	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
	{
		free_split(tokens);
		return (0);
	}
	ok = 1;
	i = 0;
	while (ok && tokens[i])
	{
		if (!parse_flag(tokens[i], cfg)) 
			ok = parse_number(tokens[i], &value) && add_number(a, value);
		i++;
	}
	free_split(tokens);
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