#include "ft_ls.h"

void	fl_swap_dev(file_info **fl)
{
	file_info *list;

	list = *fl;
	dev_t tmp;

	tmp = list->st_dev;
	list->st_dev = list->next->st_dev;
	list->next->st_dev = tmp;
}

void	fl_swap_mode(file_info **fl)
{
	file_info *list;

	list = *fl;
	mode_t tmp;

	tmp = list->st_mode;
	list->st_mode = list->next->st_mode;
	list->next->st_mode = tmp;
}

void	fl_swap_nlink(file_info **fl)
{
	file_info *list;

	list = *fl;
	nlink_t tmp;

	tmp = list->st_nlink;
	list->st_nlink = list->next->st_nlink;
	list->next->st_nlink = tmp;
}

void	fl_swap_uid(file_info **fl)
{
	file_info *list;

	list = *fl;
	uid_t tmp;

	tmp = list->st_uid;
	list->st_uid = list->next->st_uid;
	list->next->st_uid = tmp;
}
