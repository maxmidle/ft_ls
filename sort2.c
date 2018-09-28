#include "ft_ls.h"

void	ft_sort_S(file_info **fl)
{
	file_info *list;
	int i;
	int y;
	int size;

	i = 0;
	size = fl_count(fl);
	while (i < size)
	{
		y = 0;
		list = *fl;
		while (y < size - i - 1)
		{
			if (list->st_size < list->next->st_size)
				fl_swap(&list);
			y++;
			list = list->next;
		}
		i++;
	}
}

void	ft_sort_u(file_info **fl)
{
	file_info *lst;
	file_info *lsn;
	int i;
	int y;
	int size;

	i = 0;
	size = fl_count(fl);
	while (i < size)
	{
		y = 0;
		lst = *fl;
		lsn = lst->next;
		while (y < size - i - 1)
		{
			if (lst->st_atimespec.tv_sec < lsn->st_atimespec.tv_sec)
				fl_swap(&lst);
			y++;
			lst = lst->next;
			lsn = lsn->next;
		}
		i++;
	}
}

void	ft_sort_U(file_info **fl)
{
	file_info *lst;
	file_info *lsn;
	int i;
	int y;
	int size;

	i = 0;
	size = fl_count(fl);
	while (i < size)
	{
		y = 0;
		lst = *fl;
		lsn = lst->next;
		while (y < size - i - 1)
		{
			if (lst->st_btimespec.tv_sec < lsn->st_btimespec.tv_sec)
				fl_swap(&lst);
			y++;
			lst = lst->next;
			lsn = lsn->next;
		}
		i++;
	}
}

void	ft_sort_c(file_info **fl)
{
	file_info *lst;
	file_info *lsn;
	int i;
	int y;
	int size;

	i = 0;
	size = fl_count(fl);
	while (i < size)
	{
		y = 0;
		lst = *fl;
		lsn = lst->next;
		while (y < size - i - 1)
		{
			if (lst->st_ctimespec.tv_sec < lsn->st_ctimespec.tv_sec)
				fl_swap(&lst);
			y++;
			lst = lst->next;
			lsn = lsn->next;
		}
		i++;
	}
}
