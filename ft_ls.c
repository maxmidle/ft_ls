#include "ft_ls.h"

int	ft_ls(char *param, int name_error, file_info **fl)
{
	struct stat	sb;
	file_info	*list;

	list = *fl;
	if (list == NULL && name_error == 1)
		return (2);
	else if (list == NULL)
	{
		lstat(".", &sb);
		list = fl_new(sb, ".");
	}
	if (list->next == NULL)
	{
		single_file(param, list);
		fl_free(&list);
	}
	else
	{
		ft_sort(param, fl);
		multiple_dir(param, fl, 0);
	}
	return (1);
}

int	single_file(char *param, file_info *fl)
{
	if (S_ISREG(fl->st_mode) || ft_strchr(param, 'd'))
		print_file(fl, param, 1);
	else if (S_ISDIR(fl->st_mode))
		handle_dir(param, fl);
	return (1);
}

int	multiple_dir(char *param, file_info **fl, int recu)
{
	int		dir;
	file_info	*list;
	char		*last;

	dir = 0;
	list = *fl;
	if (recu == 0 && !(ft_strchr(param, 'f')))
		ft_sort(param, fl);
	if (recu == 0)
		multiple_file(*fl, param);
	while (list)
	{
		if (S_ISDIR(list->st_mode) && !(ft_strchr(param, 'd')))
		{
			last = &list->f_name[ft_strlen(list->f_name) - 1];
			if (recu == 0 || !(last[0] == '.' && last[1] == '\0'))
			{
				ft_printf("\n%s:\n", list->f_name);
				single_file(param, list);
			}
		}
		list = list->next;
	}
	fl_free(fl);
	return (1);
}

void	multiple_file(file_info *fl, char *param)
{
	file_info	*list;
	int		*parc;

	list = fl;
	
	if (ft_strchr(param, 'd'))
		parc = get_parc(list, 1);
	else
		parc = get_parc(list, 0);
	while (list)
	{
		if (!(S_ISDIR(list->st_mode)) || ft_strchr(param, 'd'))
		{
			if (ft_strchr(param, 'l'))
				print_longline(list, param, parc);
			else
			{
				if (ft_strchr(param, 'i'))
					ft_printf("%9-d", list->st_ino);
				print_name(list, param);
			}
		}
		list = list->next;
	}
	free(parc);
}

int	handle_dir(char *param, file_info *fl)
{
	DIR		*dirp;
	struct dirent	*dp;
	struct stat	sb;
	file_info	*list;
	file_info	*fl_bis;
	char		*path;

	path = NULL;
	dirp = opendir(fl->f_name);
	if (!dirp)
	{
		path = strerror(errno);
		ft_printf("ft_ls: %s: %s\n", get_name(fl->f_name), path);
		return (0);
	}
	fl_bis = NULL;
	while ((dp = readdir(dirp)))
	{
		if (((ft_strchr(param, 'a') || ft_strchr(param, 'f')) && 
			dp->d_name[0] == '.') || dp->d_name[0] != '.')
		{
			list = fl_bis;
			path = get_path(fl->f_name, dp->d_name);
			lstat(path, &sb);
			if (fl_bis == NULL)
				fl_bis = fl_new(sb, path);
			else
			{
				while (list->next)
					list = list->next;
				list->next = fl_new(sb, path);
			}
			ft_strdel(&path);
		}
	}
	if (!(ft_strchr(param, 'f')))
		ft_sort(param, &fl_bis);
	print_file(fl_bis, param, 0);
	if (ft_strchr(param, 'R'))
	{
		closedir(dirp);
		return (multiple_dir(param, &fl_bis, 1));
	}
	fl_free(&fl_bis);
	closedir(dirp);
	return (0);
}
