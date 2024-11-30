#include "ft_printf.h"

int	ft_put_hex_up(unsigned int num)
{
	char	*str;
	int		res;

	str = "0123456789ABCDEF";
	res = 0;
	if (num / 16 != 0)
		res += ft_put_hex_up(num / 16);
	return (res + ft_putchar(str[num % 16]));
}
