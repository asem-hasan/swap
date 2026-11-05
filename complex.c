#include "push_swap.h"

static size_t	get_max_bits(size_t max_index)
{
	size_t	max_bits;

	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	sort_bit(t_stack *stack_a, t_stack *stack_b, size_t size, int bit)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((stack_a->top->index >> bit) & 1) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

void	complex(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	size_t	size;
	int	bit;

	if (!stack_a || !stack_b || stack_a->size < 2)
		return ;
	assign_index(stack_a);
	size = stack_a->size;
	max_bits = get_max_bits(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		sort_bit(stack_a, stack_b, size, bit);
		bit++;
	}
}
