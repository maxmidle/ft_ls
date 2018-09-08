#ifndef FT_LS_H
# define FT_LS_H
# include "ft_printf/ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

char	**arg_verif(int ac, char **av);
int	name_verif(char *name, char **arg_ret, int ret);
int	param_verif(char *param, char **arg_ret);
int	ft_isparam(char c);
#endif
