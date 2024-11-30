#include "ft_printf.h"

int	ft_put_hex_low(unsigned int num)
{
	char	*str;
	int		res;

	str = "0123456789abcdef";
	res = 0;
	if (num / 16 != 0)
		res += ft_put_hex_low(num / 16);
	return (res + ft_putchar(str[num % 16]));
}
