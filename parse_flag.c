/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:19:39 by syaseen           #+#    #+#             */
/*   Updated: 2026/11/08 11:19:42 by syaseen          ###   ########.fr       */
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