#include "ft_ls.h"

int	ft_isparam(char c)
{
	if (c == 'R' || c == 'r' || c == 'a' || c == 't' || c == 'l' ||
		 c == 'G' || c == 'g' || c == 'f' || c == 'i' || c == 'd' ||
		 c == 'U' || c == 'u' || c == 'S' || c == 'c' || c == '1')
		return (1);
	return (0);
}
