/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:17:46 by syaseen           #+#    #+#             */
/*   Updated: 2026/11/08 11:17:49 by syaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	stack_init(t_stack *stack)
{
	if (!stack)
		return ;
	stack->top = NULL;
	stack->size = 0;
	stack->stats = NULL;
}

t_node	*stack_new_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void	stack_free(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	if (!stack)
		return ;
	node = stack->top;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	stack->top = NULL;
	stack->size = 0;
}
