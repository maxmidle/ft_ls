#include "ft_ls.h"

void	print_file(file_info *fl, char *param, int single)
{
	int *parc;
	file_info	*list;

	parc = get_parc(fl, 1);
	list = fl;
	if (ft_strchr(param, 'l') && single == 0)
		ft_printf("total %d\n", get_total(fl));
	while(list)
	{
		if (ft_strchr(param, 'l'))
			print_longline(list, param, parc);
		else
		{
			if (ft_strchr(param, 'i'))
				ft_printf("%9-llu", list->st_ino);
			print_name(list, param);
		}
		list = list->next;
	}
	free(parc);
}

void	print_longline(file_info *fl, char *param, int *parc)
{
	if (ft_strchr(param, 'i'))
		ft_printf("%9-d", fl->st_ino);
	print_perm(fl);
	parcing(parc[0] - ft_strlen(fl->f_nlink) + 1);
	ft_printf("%s ", fl->f_nlink);
	if (!(ft_strchr(param, 'g')))
	{
		ft_putstr(fl->o_name);
		parcing(parc[1] - ft_strlen(fl->o_name) + 2);
	}
	ft_putstr(fl->g_name);
	parcing(parc[2] - ft_strlen(fl->g_name) + 2);
	if (S_ISCHR(fl->st_mode) || S_ISBLK(fl->st_mode))
	{
		parcing(parc[3] - 8);
		print_minmaj(fl);
	}
	else
	{
		parcing(parc[3] - ft_strlen(fl->f_size));
		ft_putstr(fl->f_size);
	}
	print_date(fl, param);
	print_name(fl, param);
}

int	get_total(file_info *fl)
{
	int ret;
	file_info *list;

	ret = 0;
	list = fl;
	while (list)
	{
		ret = ret + list->st_blocks;
		list = list->next;
	}
	return (ret);
}

void	parcing(int i)
{
	while (i)
	{
		ft_putchar(' ');
		i--;
	}
}

int	*get_parc(file_info *fl, int fonly)
{
	int 		tmp;
	int		*parc;
	file_info	*list;

	parc = ft_memalloc(sizeof(int) * 4);
	list = fl;
	while (list)
	{
		if (fonly || !(S_ISDIR(list->st_mode)))
		{
			if (parc[0] < (tmp = ft_strlen(list->f_nlink)))
				parc[0] = tmp;
			if( parc[1] < (tmp = ft_strlen(list->o_name)))
				parc[1] = tmp;
			if (parc[2] < (tmp = ft_strlen(list->g_name)))
				parc[2] = tmp;
			if ((S_ISCHR(list->st_mode) ||
				S_ISBLK(list->st_mode)) && parc[3] < 8)
				parc[3] = 8;
			else if (parc[3] < (tmp  = ft_strlen(list->f_size)))
				parc[3] = tmp;
		}
		list = list->next;
	}
	return (parc);
}
