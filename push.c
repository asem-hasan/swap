#include "push_swap.h"

void	stack_add_top(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (!b || !a || !b->top)
		return ;
	temp = b->top;
	b->top = temp->next;
	b->size--;
	stack_add_top(a, temp);
	stats_record(a->stats, OP_PA);
	printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (!a || !b || !a->top)
		return ;
	temp = a->top;
	a->top = temp->next;
	a->size--;
	stack_add_top(b, temp);
	stats_record(a->stats, OP_PB);
	printf("pb\n");
}
