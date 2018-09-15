#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	struct stat sb;
	int ret;
	char *error;
	ret = open(av[1], O_RDONLY);
	error = strerror(ret);
	printf("%s\n", error);
	perror(error);
	return (0);
}
