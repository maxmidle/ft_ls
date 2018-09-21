#include "ft_ls.h"

char	*arg_verif(int ac, char **av, int *name_error, file_info **fl)
{
	int	i;
	int	ret;
	char	*param;

	i = 1;
	ret = 1;
	param = ft_strnew(0);
	while (i < ac && av[i][0] == '-' && ret != 2)
	{
		if (!(ret = param_verif(av[i], &param)))
			return (NULL);
		if (ret != 2)
			i++;
	}
	ret = 1;
	while (i < ac)
	{
		name_verif(av[i], name_error, fl);
		i++;
	}
	return (param);
}

int	param_verif(char *av, char **param)
{
	int	i;

	i = 1;
	if (av[i] == '\0')
		return (2);
	while (av[i])
	{
		if (ft_isparam(av[i]) && !ft_strchr(*param, av[i]))
			ft_strnconc(param, ft_strlen(*param), &av[i], 1);
		else if (!ft_isparam(av[i]))
		{
			ft_printf("ft_ls: illegal option -- %c\n", av[i]);
 			ft_printf("usage: ft_ls [-Ralrt] [file...]\n");
			free(*param);
			return (0);
		}
		i++;
	}
	return (1);
}

int	name_verif(char *name, int *error, file_info **fl)
{
	struct stat	sb;
	file_info *list;

	list = *fl;
	if (stat(name, &sb) == -1)
	{
		ft_printf("ft_ls: %s: No such file or directory\n", name);
		*error = 1;
		return (0);
	}
	if (*fl == NULL)
		*fl = fl_new(sb, name);
	else
	{
		while (list->next)
			list = list->next;
		list->next = fl_new(sb, name);
	}
	return (1);
}

file_info	*fl_new(struct stat sb, char *name)
{
	file_info	*fl;

	fl = (file_info*)malloc(sizeof(file_info));
	fl->f_name = ft_strdup(name);
	fl->st_dev = sb.st_dev;
	fl->st_mode = sb.st_mode;
	fl->st_nlink = sb.st_nlink;
	fl->st_uid = sb.st_uid;
	fl->st_gid = sb.st_gid;
	fl->st_size = sb.st_size;
	fl->st_atimespec = sb.st_atimespec;
	fl->st_mtimespec = sb.st_mtimespec;
	fl->st_ctimespec = sb.st_ctimespec;
	fl->st_birthtimespec = sb.st_birthtimespec;
	fl->next = NULL;
	return (fl);
}

int main(int ac, char **av)
{
	char *param;
	int	name_error;
	file_info	*fl;

	name_error = 0;
	fl = NULL;
	param = arg_verif(ac, av, &name_error, &fl);
	if (!param)
		return (0);
	ft_ls(param, name_error, &fl);
	free(param);
	return (0);
}
