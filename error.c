#include "ft_ls.h"

void	handle_error(char **av, int ac)
{
	int		i;
	int 		y;
	char		*tmp;
	
	i = 0;
	while (i < ac)
	{
		y = 1;
		while(y < ac - i - 1)
		{
			if (ft_strcmp(av[y], av[y + 1]) > 0)
			{
				tmp = av[y];
				av[y] = av[y + 1];
				av[y + 1] = tmp;	
			}
			y++;
		}
		i++;
	}
	print_error(av, ac);
}

void	print_error(char **av, int ac)
{
	int		i;
	struct stat	sb;

	i = 1;
	while (i < ac)
	{
		if (lstat(av[i], &sb) == -1)
		{
			ft_putstr("ft_ls: ");
			ft_putstr(av[i]);
			ft_putstr(": No such file or directory\n");
		}
		i++;
	}
}

int	ft_isparam(char c)
{
	if (c == 'R' || c == 'r' || c == 'a' || c == 't' || c == 'l' ||
		c == 'G' || c == 'g' || c == 'f' || c == 'i' || c == 'd' ||
		c == 'U' || c == 'u' || c == 'S' || c == 'c' || c == 'F' ||
		c == '1')
		return (1);
	return (0);
}
