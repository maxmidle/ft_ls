#include "libft.h"

int	ft_strclen(char *str, char c)
{
	int i;

	i = 0;
	while(str[i] && str[i] != c)
		i++;
	return (i);
}
