#include "libft.h"

void	ft_strbackconc(char **s1, char *s2)
{
	char	*tmp;

	if (!*s1)
		*s1 = ft_strnew(0);
	if (!s2)
		return ;
	tmp = ft_strdup(*s1);
	ft_strdel(s1);
	*s1 = ft_strdup(s2);
	ft_strconc(s1, tmp);
	ft_strdel(&tmp);
}
