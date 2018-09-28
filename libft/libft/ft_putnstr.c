#include "libft.h"

void	ft_putnstr(const char *str, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}
