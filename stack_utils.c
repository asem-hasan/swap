/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:18:02 by syaseen           #+#    #+#             */
/*   Updated: 2026/11/08 11:18:05 by syaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	assign_index(t_stack *stack)
{
	int		index;
	t_node	*current;
	t_node	*check;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		check = stack->top;
		index = 0;
		while (check)
		{
			if (check->value < current->value)
				index++;
			check = check->next;
		}
		current->index = index;
		current = current->next;
	}
}
