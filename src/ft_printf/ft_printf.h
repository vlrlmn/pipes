#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_put_uint(unsigned int num);
int	ft_put_hex_low(unsigned int num);
int	ft_put_hex_up(unsigned int num);
int	ft_put_pointer(unsigned long long num);

#endif