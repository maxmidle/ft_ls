#include "ft_ls.h"

void	print_minmaj(file_info *fl)
{
	int major;
	int minor;
	
	major = major(fl->st_rdev);
	minor = minor(fl->st_rdev);
	if (major < 10)
		ft_putstr("  ");
	else if (major < 100)
		ft_putstr(" ");
	ft_putnbr(major);
	ft_putstr(", ");
	if (minor < 10)
		ft_putstr("  ");
	else if (minor < 100)
		ft_putstr(" ");
	ft_putnbr(minor);
}
