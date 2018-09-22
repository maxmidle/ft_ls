#ifndef FT_LS_H
# define FT_LS_H
# include "ft_printf/ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
#include <dirent.h>
#include <time.h>

typedef struct	file_info
{
	char			*f_name;
	dev_t			st_dev;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	struct timespec		st_atimespec;
	struct timespec		st_mtimespec;
	struct timespec		st_ctimespec;
	struct timespec		st_birthtimespec;
	struct file_info	*next;
}		file_info;
	
int	ft_ls(char *param, int name_error, file_info **fl);
int	single_file(char *param, file_info *fl);
int	multiple_dir(char *param, file_info **fl, int recu);
void	multiple_file(file_info *fl);
int	handle_dir(char *param, file_info *fl);

char	*arg_verif(int ac, char **av, int *name_error, file_info **fl);
int	name_verif(char *name, int *error, file_info **fl);
file_info	*fl_new(struct stat sb, char *name);
int	param_verif(char *av, char **param);

int	ft_isparam(char c);

char	*get_path(char *path, char *name);
char	*get_name(char *name);
void	fl_free(file_info **fl);
int	fl_count(file_info **fl);

void	ft_sort(char *param, file_info **fl);
void	ft_sort_t(file_info **fl);
void	ft_sort_r(file_info **fl);
void	fl_swap(file_info **fl);

void	fl_swap_dev(file_info **fl);
void	fl_swap_mode(file_info **fl);
void	fl_swap_nlink(file_info **fl);
void	fl_swap_uid(file_info **fl);
void	fl_swap_gid(file_info **fl);
void	fl_swap_size(file_info **fl);
void	fl_swap_atime(file_info **fl);
void	fl_swap_mtime(file_info **fl);
void	fl_swap_ctime(file_info **fl);
void	fl_swap_birthtime(file_info **fl);
#endif
