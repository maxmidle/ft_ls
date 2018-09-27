#include "ft_ls.h"

int	ft_isparam(char c)
{
	if (c == 'R' || c == 'r' || c == 'a' || c == 't' || c == 'l' ||
		 c == 'G' || c == 'g' || c == 'f' || c == '1')
		return (1);
	return (0);
}
