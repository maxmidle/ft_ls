#include "ft_ls.h"

int	ft_ls(char **arg_ret, int name_error)
{
	if (ft_tablen(arg_ret) == 1 && name_error == 1)
		return (2);
	else if (ft_tablen(arg_ret) == 1)
	{
		arg_ret[1] = ft_strdup(".");
		arg_ret[2] = NULL;
	}
	if (ft_tablen(arg_ret) == 2)
			single_file(arg_ret[0], arg_ret[1]);
	else
		multiple_file(arg_ret);
	return (1);
}

int	single_file(char *param, char *file_name)
{
	struct stat sb;
	
	stat(file_name, &sb);
	if (S_ISDIR(sb.st_mode))
		handle_dir(param, file_name, sb);
	else if (S_ISREG(sb.st_mode))
		ft_printf("%s\n", get_name(file_name));
	return (1);
}

int	multiple_file(char **arg_ret)
{
	int		i;
	struct stat	sb;

	i = 1;
	while (arg_ret[i])
	{
		stat(arg_ret[i], &sb);
		if (S_ISREG(sb.st_mode))
			ft_printf("%s\n", arg_ret[i]);
		i++;
	}
	i = 1;
	while (arg_ret[i])
	{
		stat(arg_ret[i], &sb);
		if (S_ISDIR(sb.st_mode))
		{
			ft_printf("%s/:\n", get_name(arg_ret[i]));
			single_file(arg_ret[0], (arg_ret[i]));
		}
		i++;
		if (arg_ret[i] && S_ISDIR(sb.st_mode))
			ft_putchar('\n');
	}
	return (1);
}

int	handle_dir(char *param, char *dir_name, struct stat sb)
{
	DIR		*dirp;
	struct dirent	*dp;

	dirp = opendir(dir_name);
	sb.st_mode = S_IFDIR;
	param = NULL;
	while ((dp = readdir(dirp)))
		ft_printf("%s\n", dp->d_name);
	closedir(dirp);
	return (0);
}
