#include "ft_ls.h"

char	*get_path(char *path, char *name)
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

char	*get_name(char *name)
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

void	fl_free(file_info **fl)
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

int	fl_count(file_info **fl)
{
	int count;
	file_info *list;
	
	count = 0;
	list = *fl;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}
