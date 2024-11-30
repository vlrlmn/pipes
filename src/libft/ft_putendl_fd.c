#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	n;

	if (!s)
		return ;
	i = 0;
	n = '\n';
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, &n, 1);
}
