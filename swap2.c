#include "ft_ls.h"

void	fl_swap_dev(file_info **fl)
{
	file_info *list;
	dev_t tmp;

	list = *fl;

	tmp = list->st_dev;
	list->st_dev = list->next->st_dev;
	list->next->st_dev = tmp;
	tmp = list->st_rdev;
	list->st_rdev = list->next->st_rdev;
	list->next->st_rdev = tmp;
}

void	fl_swap_mode(file_info **fl)
{
	file_info *list;
	mode_t	tmp;
	ino_t	inotmp;

	list = *fl;

	tmp = list->st_mode;
	list->st_mode = list->next->st_mode;
	list->next->st_mode = tmp;
	inotmp = list->st_ino;
	list->st_ino = list->next->st_ino;
	list->next->st_ino = inotmp;
}

void	fl_swap_nlink(file_info **fl)
{
	file_info	*list;
	nlink_t		tmp;
	char		*chtmp;

	list = *fl;

	tmp = list->st_nlink;
	chtmp = list->f_nlink;
	list->st_nlink = list->next->st_nlink;
	list->f_nlink = list->next->f_nlink;
	list->next->st_nlink = tmp;
	list->next->f_nlink = chtmp;
}

void	fl_swap_uid(file_info **fl)
{
	file_info *list;
	char *tmp;

	list = *fl;
	tmp = list->o_name;
	list->o_name = list->next->o_name;
	list->next->o_name = tmp;
}
