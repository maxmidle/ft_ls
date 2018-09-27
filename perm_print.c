#include "ft_ls.h"

void	print_perm(file_info *fl)
{
	char	*perm;
	
	print_type(fl);
	perm = ft_strdup("---------");
	if (fl->st_mode & S_IRUSR)
		perm[0] = 'r';
	if (fl->st_mode & S_IWUSR)
		perm[1] = 'w';
	if (fl->st_mode & S_IXUSR)
		perm[2] = 'x';
	if (fl->st_mode & S_IRGRP)
		perm[3] = 'r';
	if (fl->st_mode & S_IWGRP)
		perm[4] = 'w';
	if (fl->st_mode & S_IXGRP)
		perm[5] = 'x';
	if (fl->st_mode & S_IROTH)
		perm[6] = 'r';
	if (fl->st_mode & S_IWOTH)
		perm[7] = 'w';
	if (fl->st_mode & S_IXOTH)
		perm[8] = 'x';
	ft_putstr(perm);
	free(perm);
}

void	print_type(file_info *fl)
{
	if (S_ISFIFO(fl->st_mode))
		ft_putchar('p');
	else if (S_ISCHR(fl->st_mode))
		ft_putchar('c');
	else if (S_ISDIR(fl->st_mode))
		ft_putchar('d');
	else if (S_ISBLK(fl->st_mode))
		ft_putchar('b');
	else if (S_ISREG(fl->st_mode))
		ft_putchar('-');
	else if (S_ISLNK(fl->st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(fl->st_mode))
		ft_putchar('s');
}
