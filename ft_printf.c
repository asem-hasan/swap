
#include "push_swap.h"

static int	ft_conversion(int fd, const char type, va_list vargs)
{
	int		len;

	len = 0;
	if (type == 'c')
		len += ft_printf_chr(fd, va_arg(vargs, int));
	else if (type == 's')
		len += ft_printf_str(fd, va_arg(vargs, char *));
	else if (type == 'd' || type == 'i')
		len += ft_printf_nbr(fd, va_arg(vargs, int));
	else if (type == '%')
		return (ft_printf_chr(fd, '%'));
	return (len);
}

int	ft_printf(int fd, const char *str, ...)
{
	int		i;
	int		len;
	va_list	vargs;

	if (!str)
		return (-1);
	len = 0;
	i = 0;
	va_start(vargs, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
				len += ft_conversion(fd, str[++i], vargs);
		}
		else
			len += ft_printf_chr(fd, str[i]);
		i++;
	}
	va_end(vargs);
	return (len);
}
