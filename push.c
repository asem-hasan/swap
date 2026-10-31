#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (!b || !a || !b->top)
		return ;
	temp = b->top;
	b->top = temp->next;
	b->size--;
	stack_add_top(a, temp);
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
	printf("pb\n");
}
