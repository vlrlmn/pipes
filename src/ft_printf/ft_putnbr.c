#include "ft_printf.h"
#include <limits.h>

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == INT_MIN)
		i = ft_putstr("-2147483648");
	else if (n < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(n * -1);
	}
	else if (n >= 0)
	{
		if (n > 9)
			i += ft_putnbr(n / 10);
		i += ft_putchar(n % 10 + 48);
	}
	return (i);
}
