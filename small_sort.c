#include "push_swap.h"

static int	find_min_pos(t_stack *a)
{
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	current = a->top;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	size_t	pos;

	pos = find_min_pos(a);
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < a->size)
			rra(a);
	}
	pb(a, b);
}

static void	sort_three_cases(t_stack *a, int first, int second, int third)
{
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void	sort_three(t_stack *a)
{
	if (a->size < 2)
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
		return ;
	}
	sort_three_cases(a, a->top->value, a->top->next->value,
		a->top->next->next->value);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (!a || !b || !a->top || a->size > 5)
		return ;
	while (a->size > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
