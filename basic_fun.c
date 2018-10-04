#include "ft_ls.h"

char		*get_path(char *path, char *name)
{
	int	i;
	char	*tmp;

	tmp = NULL;
	tmp = ft_strdup(path);
	i = ft_strlen(path) - 1;
	ft_strcpy(path, tmp);
	if (tmp[i] != '/')
		ft_strconc(&tmp, "/");
	ft_strconc(&tmp, name);
	return (tmp);
}

char		*get_name(char *name)
{
	int i;
	int tmp;
	int endtmp;

	i = 0;
	tmp = 0;
	endtmp = ft_strlen(name) - 1;
	if (name[endtmp] == '/')
		name[endtmp] = '\0';
	while (name[i])
	{
		if (name[i] == '/')
			tmp = i;
		i++;
	}
	if (name[tmp] == '/')
		tmp++;
	if (name[endtmp] == '\0')
		name[endtmp] = '/';
	return (&name[tmp]);
}

void		fl_free(file_info **fl)
{
	file_info *list;

	list = fl[0];
	while (list)
	{
		free(list->f_name);
		free(list->f_nlink);
		free(list->f_size);
		free(list->o_name);
		free(list->g_name);
		list = list->next;
		free(*fl);
		*fl = list;
	}
}

int		fl_count(file_info **fl)
{
	int		count;
	file_info	*list;
	
	count = 0;
	list = *fl;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

file_info	*fl_fill(char *param, DIR *dirp, file_info *fl)
{
	file_info	*fl_bis;
	file_info	*list;;
	char 		*path;
	struct dirent	*dp;
	struct stat	sb;

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
	return (fl_bis);
}
