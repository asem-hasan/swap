/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:20:28 by syaseen           #+#    #+#             */
/*   Updated: 2026/11/08 11:20:32 by syaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	compute_disorder(t_stack *a)
{
	t_node		*i;
	t_node		*j;
	long long	pair;
	long long	mistakes;

	i = a->top;
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
