#include "ft_ls.h"

void	fl_swap_atime(file_info **fl)
{
	file_info *list;
	time_t tmp;
	long longtmp;

	list = *fl;
	tmp = list->st_atimespec.tv_sec;
	list->st_atimespec.tv_sec = list->next->st_atimespec.tv_sec;
	list->next->st_atimespec.tv_sec = tmp;
	longtmp = list->st_atimespec.tv_nsec;
	list->st_atimespec.tv_nsec = list->next->st_atimespec.tv_nsec;
	list->next->st_atimespec.tv_nsec = longtmp;
}

void	fl_swap_mtime(file_info **fl)
{
	file_info *list;
	time_t tmp;
	long longtmp;

	list = *fl;
	tmp = list->st_mtimespec.tv_sec;
	list->st_mtimespec.tv_sec = list->next->st_mtimespec.tv_sec;
	list->next->st_mtimespec.tv_sec = tmp;
	longtmp = list->st_mtimespec.tv_nsec;
	list->st_mtimespec.tv_nsec = list->next->st_mtimespec.tv_nsec;
	list->next->st_mtimespec.tv_nsec = longtmp;
}

void	fl_swap_ctime(file_info **fl)
{
	file_info *list;
	time_t tmp;
	long longtmp;

	list = *fl;
	tmp = list->st_ctimespec.tv_sec;
	list->st_ctimespec.tv_sec = list->next->st_ctimespec.tv_sec;
	list->next->st_ctimespec.tv_sec = tmp;
	longtmp = list->st_ctimespec.tv_nsec;
	list->st_ctimespec.tv_nsec = list->next->st_ctimespec.tv_nsec;
	list->next->st_ctimespec.tv_nsec = longtmp;
}

void	fl_swap_birthtime(file_info **fl)
{
	file_info *list;
	time_t tmp;
	long longtmp;

	list = *fl;
	tmp = list->st_btimespec.tv_sec;
	list->st_btimespec.tv_sec = list->next->st_btimespec.tv_sec;
	list->next->st_btimespec.tv_sec = tmp;
	longtmp = list->st_btimespec.tv_nsec;
	list->st_btimespec.tv_nsec = list->next->st_btimespec.tv_nsec;
	list->next->st_btimespec.tv_nsec = longtmp;
}
