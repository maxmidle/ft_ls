#include "ft_printf.h"

int	ft_isconv(char c)
{
	if (c == 'l' || c == 'h' || c == 'z' || c == 'j')
		return (1);
	return (0);
}

int	ft_isnumconv(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' ||
		c == 'u' || c == 'U' || c == 'x' || c == 'x' || c == 'b')
		return (1);
	return (0);
}

int	ft_isarg(char c)
{
										
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == 'b')
		return (1);
	return (0);
}
