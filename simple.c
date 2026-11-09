/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:18:59 by syaseen           #+#    #+#             */
/*   Updated: 2026/11/08 11:19:01 by syaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_find_min_pos(t_stack *stack)
{
	t_node		*node;
	int			min;
	int			min_pos;
	int			i;

	node = stack->top;
	min = node->value;
	i = 0;
	min_pos = 0;
	while (node)
	{
		if (node->value < min)
		{
			min = node->value;
			min_pos = i;
		}
		i++;
		node = node->next;
	}
	return (min_pos);
}

static void	transfer(t_stack *stack_a, t_stack *stack_b,
		size_t moves, int flag)//flag = 1 or 0; 1 = ra, 0 = rra;
{
	size_t	i;

	i = 0;
	while (i < moves)
	{
		if (flag)
			ra(stack_a);
		else
			rra(stack_a);
		i++;
	}
	pb(stack_a, stack_b);
}

static void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	node = stack_b->top;
	while (node)
	{
		pa(stack_a, stack_b);
		node = stack_b->top;
	}
}

void	simple(t_stack *stack_a, t_stack *stack_b)
{
	size_t	min_pos;
	size_t	moves;

	if (!stack_a || !stack_a->top)
		return ;
	if (stack_a->size <= 5)
	{
		sort_small(stack_a, stack_b);
		return ;
	}
	while (stack_a->size > 0)
	{
		min_pos = ft_find_min_pos(stack_a);
		if (min_pos < stack_a->size / 2)
		{
			moves = min_pos;
			transfer(stack_a, stack_b, moves, 1);
		}
		else
		{
			moves = stack_a->size - min_pos;
			transfer(stack_a, stack_b, moves, 0);
		}
	}
	sort(stack_a, stack_b);
}
