/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:18:14 by syaseen           #+#    #+#             */
/*   Updated: 2026/11/08 11:18:17 by syaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node	*temp;

	if (!a || a->size < 2)
		return ;
	temp = a->top;
	a->top = temp->next;
	temp->next = a->top->next;
	a->top->next = temp;
	stats_record(a->stats, OP_SA);
	ft_printf(1, "%s", "sa\n");
}

void	sb(t_stack *b)
{
	t_node	*temp;

	if (!b || b->size < 2)
		return ;
	temp = b->top;
	b->top = temp->next;
	temp->next = b->top->next;
	b->top->next = temp;
	stats_record(b->stats, OP_SB);
	ft_printf(1, "%s", "sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	t_node	*temp;
	int		done;

	done = 0;
	if (a && a->size >= 2)
	{
		temp = a->top;
		a->top = temp->next;
		temp->next = a->top->next;
		a->top->next = temp;
		done = 1;
	}
	if (b && b->size >= 2)
	{
		temp = b->top;
		b->top = temp->next;
		temp->next = b->top->next;
		b->top->next = temp;
		done = 1;
	}
	if (done)
	{
		stats_record(a->stats, OP_SS);
		ft_printf(1, "%s", "ss\n");
	}
}
