#include "ft_ls.h"

void	print_acl(file_info *fl)
{
	acl_t		acl;
	acl_entry_t	dummy;
	ssize_t xattr;

	acl = NULL;
	xattr = 0;
	acl = acl_get_link_np(fl->f_name, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(fl->f_name, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		ft_putchar('@');
	else if (acl != NULL)
	{
		ft_putchar('+');
		acl_free(acl);
	}
	else
		ft_putchar(' ');
}
