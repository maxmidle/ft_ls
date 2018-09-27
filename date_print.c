#include "ft_ls.h"

void	print_date(file_info *fl, char *param)
{
	if (ft_strchr(param, 't'))
		print_parcdate(fl->st_mtimespec.tv_sec);
	else if (ft_strchr(param, 'u'))
		print_parcdate(fl->st_atimespec.tv_sec);
	else if (ft_strchr(param, 't'))
		print_parcdate(fl->st_birthtimespec.tv_sec);
	else
		print_parcdate(fl->st_mtimespec.tv_sec);
}

void	print_parcdate(time_t date)
{
	time_t	today;
	char	*str;

	today = time(&today);
	str = ctime(&date);
	if (date > today || today - date > 15778800)
	{
		str[11] = ' ';
		str[12] = str[20];
		str[13] = str[21];
		str[14] = str[22];
		str[15] = str[23];
	}
	ft_putnstr(&str[3], 13);
}
