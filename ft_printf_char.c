#include "push_swap.h"

int	ft_printf_chr(int fd, char c)
{
	return (write(fd, &c, 1));
}
