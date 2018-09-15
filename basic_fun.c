#include "ft_ls.h"

char	*get_name(char *path)
{
	int	last;
	int	i;

	i = 0;
	last = ft_strlen(path) - 1;
	while (path[last] == '/')
		last--;
	path[last + 1] = '\0';
	return (path);
}
