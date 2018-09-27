#include "ft_ls.h"

void	fl_swap_gid(file_info **fl)
{
	char		*tmp;
	file_info	*list;

	list = *fl;

	tmp = list->g_name;
	list->g_name = list->next->g_name;
	list->next->g_name = tmp;
}

void	fl_swap_size(file_info **fl)
{
	file_info	*list;
	off_t		tmp;
	char		*chtmp;

	list = *fl;

	tmp = list->st_size;
	chtmp = list->f_size;
	list->st_size = list->next->st_size;
	list->f_size = list->next->f_size;
	list->next->st_size = tmp;
	list->next->f_size = chtmp;
}

void	fl_swap_block(file_info **fl)
{
	file_info	*list;
	blkcnt_t	tmp;

	list = *fl;

	tmp = list->st_blocks;
	list->st_blocks = list->next->st_blocks;
	list->next->st_blocks = tmp;
}
