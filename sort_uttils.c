#include "push_swap.h"

int is_sorted(t_stack *a)
{
    t_node *current;

    if (!a || !a->top)
        return (1);
    current = a->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}
