#include "ft_ls.h"

void	print_name(file_info *fl, char *param)
{
	char	buff[1024];
	size_t	len;

	len = 0;
	if (S_ISLNK(fl->st_mode) && ft_strchr(param, 'l'))
	{
		len = readlink(fl->f_name, buff, sizeof(buff));
		buff[len] = '\0';
	}
	if (ft_strchr(param, 'G'))
		print_colorname(fl);
	else
		ft_putstr(get_name(fl->f_name));
	if (ft_strchr(param, 'F'))
		print_typename(fl);
	if (len > 0)
		ft_printf("\x1B[0m -> %s", buff);
	ft_putstr("\x1B[0m\n");
}

void	print_colorname(file_info *fl)
{
	if (S_ISFIFO(fl->st_mode))
		ft_printf("\x1B[33m%s", get_name(fl->f_name));
	else if (S_ISCHR(fl->st_mode))
		ft_printf("\x1B[32m%s", get_name(fl->f_name));
	else if (S_ISDIR(fl->st_mode))
		ft_printf("\x1B[34m%s", get_name(fl->f_name));
	else if (S_ISBLK(fl->st_mode))
		ft_printf("\x1B[93m%s", get_name(fl->f_name));
	else if (S_ISREG(fl->st_mode) && ((fl->st_mode & S_IXUSR) ||
			(fl->st_mode & S_IXGRP) || (fl->st_mode & S_IXOTH)))
	{
		ft_printf("\x1B[31m%s", get_name(fl->f_name));
	}
	else if (S_ISREG(fl->st_mode))
		ft_printf("\x1b[47m\x1B[30m%s", get_name(fl->f_name));
	else if (S_ISLNK(fl->st_mode))
		ft_printf("\x1B[36m%s", get_name(fl->f_name));
	else if (S_ISSOCK(fl->st_mode))
		ft_printf("\x1B[35m%s", get_name(fl->f_name));
}

void	print_typename(file_info *fl)
{
	if (S_ISDIR(fl->st_mode))
		ft_putchar('/');
	else if (S_ISREG(fl->st_mode) && ((fl->st_mode & S_IXUSR) ||
			(fl->st_mode & S_IXGRP) || (fl->st_mode & S_IXOTH)))
		ft_putchar('*');
	else if (S_ISLNK(fl->st_mode))
		ft_putchar('@');
	else if (S_ISSOCK(fl->st_mode))
		ft_putchar('=');
	else if (S_ISWHT(fl->st_mode))
		ft_putchar('%');
	else if (S_ISFIFO(fl->st_mode))
		ft_putchar('|');
}
