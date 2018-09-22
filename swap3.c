#include "ft_ls.h"

void	fl_swap_gid(file_info **fl)
{
	file_info *list;

	list = *fl;
	gid_t tmp;

	tmp = list->st_gid;
	list->st_gid = list->next->st_gid;
	list->next->st_gid = tmp;
}

void	fl_swap_size(file_info **fl)
{
	file_info *list;

	list = *fl;
	off_t tmp;

	tmp = list->st_size;
	list->st_size = list->next->st_size;
	list->next->st_size = tmp;
}
