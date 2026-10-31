#include "push_swap.h"

static	t_node	*find_last(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

static	int	rotate(t_stack *s)
{
	t_node	*temp;
	t_node	*last;

	if (!s || s->size < 2)
		return (0);
	temp = s->top->next;
	last = find_last(s);
	last->next = s->top;
	s->top->next = NULL;
	s->top = temp;
	return (1);
}

void	ra(t_stack *a)
{
	if (rotate(a))
		printf("ra\n");
}

void	rb(t_stack *b)
{
	if (rotate(b))
		printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	int	done;

	done = rotate(a);
	done |= rotate(b);
	if (done)
		printf("rr\n");
}
