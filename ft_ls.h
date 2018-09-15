#ifndef FT_LS_H
# define FT_LS_H
# include "ft_printf/ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
#include <dirent.h>

int	ft_ls(char **arg_ret, int name_error);
int	single_file(char *param, char *file_name);
int	multiple_file(char **arg_ret);
int	handle_dir(char *param, char *dir_name, struct stat sb);

char	**arg_verif(int ac, char **av, int *name_error);
int	name_verif(char *name, char **arg_ret, int ret, int *name_error);
int	param_verif(char *param, char **arg_ret);

int	ft_isparam(char c);

char	*get_name(char *path);
#endif
