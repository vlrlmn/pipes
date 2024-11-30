#include "libft.h"

int	ft_isdigit(int d)
{
	if ((d >= 48 && d <= 57) || d == 32 || d == '-')
		return (1);
	else
		return (0);
}
