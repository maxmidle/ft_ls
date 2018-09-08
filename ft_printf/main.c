#include "ft_printf.h"
#include <locale.h>
int main()
{
    char *l = setlocale(LC_ALL, "");
    if (!l)
        printf("setlocale error\n");
    long long f = -9223372036854775806;
    long long a = 128;
    unsigned long long b = 18446744073709551614;
    wchar_t *c = L"tèst";
    char *e = "test";
    wint_t d = 256;
    char g = 'g';
    int ret;
    ret = ft_printf("%lld et %ll020x puisé%05% dot %010.ls encore %lc et enfin %010p\n", a, f, c, d, e);
    printf("%d\n", ret);
    ret = printf("%lld et %ll020x puisé%05% dot %010.ls encore %lc et enfin %010p\n", a, f, c, d, e);
	printf("%d\n", ret);
	return (0);
}
