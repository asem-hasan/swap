/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 13:09:35 by syaseen           #+#    #+#             */
/*   Updated: 2026/10/31 13:11:45 by syaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	compute_disorder(t_node *a)
{
	t_node		*i;
	t_node		*j;
	long long	pair;
	long long	mistakes;

	i = a;
	pair = 0;
	mistakes = 0;
	while (i)
	{
		j = i->next;
		while (j)
		{
			pair++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (pair == 0)
		return (0);
	return (mistakes * 10000 / pair);
}
