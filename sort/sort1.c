#include "../ft_ls.h"

void	ft_sort(char *param, file_info **fl)
{
	int i;

	i = 0;
		ft_sort_ascii(fl);
	while (param[i])
	{
		if (param[i] == 't' && !(ft_strchr(param, 'S')))
		{
			if (ft_strchr(param, 'u'))
				ft_sort_u(fl);
			else if (ft_strchr(param, 'U'))
				ft_sort_U(fl);
			else if (ft_strchr(param, 'c'))
				ft_sort_c(fl);
			else if (ft_strchr(param, 't'))
				ft_sort_t(fl);
			i = ft_strlen(param) - 1;
		}
		i++;
	}
	if (ft_strchr(param, 'S'))
		ft_sort_S(fl);
	if (ft_strchr(param, 'r'))
		ft_sort_r(fl);
}

void	fl_swap(file_info **fl)
{
	file_info	*list;
	char		*tmp;

	list = *fl;
	tmp = list->f_name;
	list->f_name = list->next->f_name;
	list->next->f_name = tmp;
	fl_swap_dev(fl);
	fl_swap_mode(fl);
	fl_swap_nlink(fl);
	fl_swap_uid(fl);
	fl_swap_gid(fl);
	fl_swap_size(fl);
	fl_swap_atime(fl);
	fl_swap_mtime(fl);
	fl_swap_ctime(fl);
	fl_swap_birthtime(fl);
	fl_swap_block(fl);
}

void	ft_sort_ascii(file_info **fl)
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
			if (ft_strcmp(list->f_name, list->next->f_name) > 0)
				fl_swap(&list);
			y++;
			list = list->next;
		}
		i++;
	}
}

void	ft_sort_t(file_info **fl)
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
			if (lst->st_mtimespec.tv_sec < lsn->st_mtimespec.tv_sec)
				fl_swap(&lst);
			y++;
			lst = lst->next;
			lsn = lsn->next;
		}
		i++;
	}
}

void	ft_sort_r(file_info **fl)
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
			fl_swap(&list);
			y++;
			list = list->next;
		}
		i++;
	}
}
