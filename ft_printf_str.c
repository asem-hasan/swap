#include "push_swap.h"

int	ft_printf_str(int fd, char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (write(fd, "(null)", 6));
	}
	while (str[i])
	{
		ft_printf_chr(fd, str[i]);
		i++;
	}
	return (i);
}
