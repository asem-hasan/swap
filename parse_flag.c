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
		cfg->strategy = 1;
	else if (ft_strcmp(arg, "--medium") == 0)
		cfg->strategy = 2;
	else if (ft_strcmp(arg, "--complex") == 0)
		cfg->strategy = 3;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		cfg->strategy = 0;
	else
		return (0);
	return (1);
}
