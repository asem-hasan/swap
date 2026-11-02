/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:08:18 by syaseen           #+#    #+#             */
/*   Updated: 2026/10/28 15:10:01 by syaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	parse_flag(const char *arg, t_config *cfg)
{
	if (ft_strcmp(arg, "--bench") == 0)
		cfg->bench = 1;
	else if (ft_strcmp(arg, "--simple") == 0)
		cfg->strategy = STRAT_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		cfg->strategy = STRAT_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		cfg->strategy = STRAT_COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		cfg->strategy = STRAT_ADAPTIVE;
	else
		return (0);
	return (1);
}

/*int main(int argc, char **argv)
{
	t_config cfg;
	int i = 1;

	
	while (i < argc)
	{
		if (parse_flag(argv[i], &cfg))
			printf("flag:   %s\n", argv[i]);
		else
			printf("number: %s\n", argv[i]);
		i++;
	}
	printf("strategy=%d bench=%d\n", cfg.strategy, cfg.bench);
}*/