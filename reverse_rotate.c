#include "push_swap.h"

static	void	find_last_and_before(t_stack *stack, t_node **last,
		t_node **blast)
{
	t_node	*current;

	current = stack->top;
	while (current->next->next != NULL)
	{
		current = current->next;
	}
	(*blast) = current;
	(*last) = current->next;
}

static int	rev_rotate(t_stack *s)
{
	t_node	*first;
	t_node	*last;
	t_node	*blast;

	if (!s || s->size < 2)
		return (0);
	first = s->top;
	find_last_and_before(s, &last, &blast);
	s->top = last;
	last->next = first;
	blast->next = NULL;
	return (1);
}

void	rrr(t_stack *a, t_stack *b)
{
	int	done;

	done = rev_rotate(a);
	done |= rev_rotate(b);
	if (done)
		printf("rrr\n");
}

void	rra(t_stack *a)
{
	if (rev_rotate(a))
		printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (rev_rotate(b))
		printf("rrb\n");
}
