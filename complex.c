#include "push_swap.h"

static int	get_max_bits(int max_index)
{
	int	max_bits;

	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	sort_bit(t_stack *a, t_stack *b, int size, int bit)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((a->top->index >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	while (b->size > 0)
		pa(a, b);
}

void	complex(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	size;
	int	bit;

	if (!a || !b || a->size < 2)
		return ;
	assign_index(a);
	size = a->size;
	max_bits = get_max_bits(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		sort_bit(a, b, size, bit);
		bit++;
	}
}
