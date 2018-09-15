#include "ft_ls.h"

char	**arg_verif(int ac, char **av, int *name_error)
{
	int	i;
	int	ret;
	char	**arg_ret;

	i = 1;
	ret = 1;
	arg_ret = (char **)malloc(sizeof(char *) * ac + 1);
	arg_ret[0] = ft_strnew(0);
	while (i < ac && av[i][0] == '-' && ret != 2)
	{
		if (!(ret = param_verif(av[i], arg_ret)))
			return (NULL);
		if (ret != 2)
			i++;
	}
	ret = 1;
	while (i < ac)
	{
		if (name_verif(av[i], arg_ret, ret, name_error))
			ret++;
		i++;
	}
	arg_ret[ret] = NULL;
	return (arg_ret);
}

int	param_verif(char *param, char **arg_ret)
{
	int	i;

	i = 1;
	if (param[i] == '\0')
		return (2);
	while (param[i])
	{
		if (ft_isparam(param[i]) && !ft_strchr(*arg_ret, param[i]))
			ft_strnconc(arg_ret, ft_strlen(*arg_ret), &param[i], 1);
		else if (!ft_isparam(param[i]))
		{
			ft_printf("ft_ls: illegal option -- %c\n", param[i]);
 			ft_printf("usage: ft_ls [-Ralrt] [file...]\n");
			free(arg_ret);
			free(*arg_ret);
			return (0);
		}
		i++;
	}
	return (1);
}

int	name_verif(char *name, char **arg_ret, int ret, int *name_error)
{
	struct stat	sb;

	if (stat(name, &sb) == -1)
	{
		ft_printf("ft_ls: %s: No such file or directory\n", name);
		*name_error = 1;
		return (0);
	}
	arg_ret[ret] = ft_strdup(name);
	return (1);
}

int main(int ac, char **av)
{
	int i = 0;
	char **arg_ret;
	int	name_error;

	name_error = 0;
	arg_ret = arg_verif(ac, av, &name_error);
	if (!arg_ret)
		return (0);
	ft_ls(arg_ret, name_error);
	while (arg_ret[i])
	{
		free(arg_ret[i]);
		i++;
	}
	free(arg_ret);
	return (0);
}
