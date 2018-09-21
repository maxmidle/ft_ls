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

	i = 0;
	tmp = ft_strlen(name) - 1;
	if (name[tmp] == '/')
		name[tmp] = '\0';
	tmp = 0;
	while (name[i])
	{
		if (name[i] == '/')
			tmp = i;
		i++;
	}
	return (&name[tmp + 1]);
}

void	fl_free(file_info **fl)
{
	file_info *list;

	list = fl[0];
	while (list)
	{
		free(list->f_name);
		list = list->next;
		free(*fl);
		*fl = list;
	}
}
