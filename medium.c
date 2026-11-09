/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:22:37 by syaseen           #+#    #+#             */
/*   Updated: 2026/11/08 11:58:21 by syaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	bring_max_to_top_and_push_to_a(t_stack *stack_a, t_stack *stack_b,
		size_t moves, int flag)//flag = 1 or 0; 1 = rb, 0 = rrb;
{
	size_t	i;

	i = 0;
	while (i < moves)
	{
		if (flag)
			rb(stack_b);
		else
			rrb(stack_b);
		i++;
	}
	pa(stack_a, stack_b);
}

static size_t	find_index_position(t_stack *stack_b, size_t max_index)
{
	t_node	*node;
	size_t	i;

	node = stack_b->top;
	i = 0;
	while (node)
	{
		if (node->index == max_index)
			break ;
		node = node->next;
		i++;
	}
	return (i);
}

static void	push_all_to_a(t_stack *stack_a, t_stack *stack_b)
{
	size_t	max_index;
	size_t	pos;
	size_t	moves;

	while (stack_b->size)
	{
		max_index = stack_b->size - 1;
		pos = find_index_position(stack_b, max_index);
		if (pos <= stack_b->size / 2)
		{
			moves = pos;
			bring_max_to_top_and_push_to_a(stack_a, stack_b, moves, 1);
		}
		else
		{
			moves = stack_b->size - pos;
			bring_max_to_top_and_push_to_a(stack_a, stack_b, moves, 0);
		}
	}
}

static void	push_chunk_to_b(t_stack *stack_a, t_stack *stack_b,
			size_t start, size_t end)
{
	t_node	*node;
	size_t	mid;
	size_t	index;
	size_t	count;

	count = stack_a->size;
	mid = (start + end) / 2;
	while (count--)
	{
		node = stack_a->top;
		if (node->index >= start && node->index <= end)
		{
			index = node->index;
			pb(stack_a, stack_b);
			if (index <= mid)
				rb(stack_b);
		}
		else
			ra(stack_a);
	}
}

void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	size_t	chunk_size;
	size_t	start;
	size_t	end;

	if (stack_a->size <= 5)
	{
		sort_small(stack_a, stack_b);
		return ;
	}
	chunk_size = ft_isqrt(stack_a->size);
	start = 0;
	end = start + chunk_size - 1;
	while (stack_a->size > 0)
	{
		push_chunk_to_b(stack_a, stack_b, start, end);
		start = end + 1;
		end = start + chunk_size - 1;
	}
	push_all_to_a(stack_a, stack_b);
}
