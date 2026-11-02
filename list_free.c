#include "push_swap.h"

void	list_free(t_node **a)
{
	t_node	*next;

	while (*a)
	{
		next = (*a)->next;
		free(*a);
		*a = next;
	}
}