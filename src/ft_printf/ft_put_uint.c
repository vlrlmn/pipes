#include "ft_printf.h"

int	ft_put_uint(unsigned int num)
{
	int	i;

	i = 0;
	if (num > 9)
		i += ft_put_uint(num / 10);
	i += ft_putchar(num % 10 + '0');
	return (i);
}
