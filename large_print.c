#include "ft_ls.h"

void	print_file(file_info *fl, char *param)
{
	int *parc;
	file_info	*list;

	parc = get_parc(fl);
	list = fl;
	while(list)
	{
		if (ft_strchr(param, 'l'))
			print_longline(list, parc, param);
		else
			ft_printf("%s\n", list->f_name);
		list = list->next;
	}
	free(parc);
}

void	print_longline(file_info *fl, char *param, int *parc)
{
	print_perm(fl);
	parcing(parc[0] - ft_strlen(fl->f_nlink))
	ft_putstr(fl->f_nlink);
	ft_puchar(' ');
	ft_putstr(fl->o_name);
	parcing(parc[1] - ft_strlen(fl->o_name) + 2);
	ft_putstr(fl->g_name);
	parcing(parc[2] - ft_strlen(fl->g_name) + 2);
	parcing(parc[3] - ft_strlen(fl->f_size));
	ft_putstr(fl->f_size);
	print_date(fl, param);
	print_name(fl, param);
}

void	parcing(int i)
{
	while (i)
	{
		ft_putchar(' ');
		i--;
	}
}

int	*get_parc(file_info *fl);
{
	int		*parc;
	file_info	*list;
	int		tmp;

	parc = NULL;
	parc = (int *)malloc(sizeof(int) * 4);
	list = fl;
	while (list)
	{
		if (parc[0] < (tmp = ft_strlen(list->f_nlink)))
			parc[0] = tmp;
		if( parc[1] < (tmp = ft_strlen(list->o_name)))
			parc[1] = tmp;
		if (parc[2] < (tmp = ft_strlen(list->g_name)))
			parc[2] = tmp;
		if (parc[3] < (tmp  = ft_strlen(list->f_size)))
			parc[3] = tmp;
		list = list->next;
	}
	return (parc);
}
