#include "push_swap.h"

void	assign_index(t_stack *stack)
{
	int	index;
	t_node	*current;
	t_node	*check;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		check = current;
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
