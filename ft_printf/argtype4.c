/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argtype4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radler <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:44:37 by radler            #+#    #+#             */
/*   Updated: 2018/06/21 20:26:22 by radler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*argtype_wint_t(char *argtype, va_list ap)
{
	wint_t	arg;
	char	c;

	arg = va_arg(ap, wint_t);
	if (ft_strstr(argtype, "lc") || ft_strstr(argtype, "C"))
	{
		if (MB_CUR_MAX == 1)
		{
			if (arg <= 255)
			{
				c = (char)arg;
				return (ft_strndup(&c, 1));
			}
			return (NULL);
		}
		return (ft_witoa(arg));
	}
	return (NULL);
}

char	*argtype_wchar_t(char *argtype, va_list ap)
{
	wchar_t	*arg;
	int		i;
	char	*str;
	char	*buff;
	char	c;

	arg = va_arg(ap, wchar_t*);
	i = 0;
	buff = NULL;
	if (ft_strstr(argtype, "ls") || ft_strstr(argtype, "S"))
	{
		str = ft_strnew(0);
		while (arg[i++])
		{
			c = (char)arg[i];
			if (MB_CUR_MAX == 1 && arg[i] <= 255)
				buff = ft_strndup(&c, 1);
			if (MB_CUR_MAX == 1 && arg[i] > 255)
				return (ft_werror(&buff, &str));
			if (MB_CUR_MAX != 1)
				buff = ft_witoa((wint_t)arg[i]);
			ft_strconc(&str, buff);
			free(buff);
		}
		return (str);
	}
	return (NULL);
}

char	*ft_witoa(wint_t nbr)
{
	char	*str;
	char	*c;

	c = (char*)&nbr;
	if (nbr < 0 || nbr > 0x10ffff)
		return (NULL);
	if (nbr <= 0x7f)
		return (ft_strndup(c, 1));
	str = ft_strnew(4);
	if (nbr <= 0x7ff)
		str[0] = (char)(nbr / 64 + 192);
	else if (nbr <= 0xffff)
	{
		str[0] = (char)(nbr / (64 * 64) + 224);
		str[1] = (char)((nbr / 64) % 64 + 128);
	}
	else if (nbr <= 0x10ffff)
	{
		str[0] = (char)(nbr / (64 * 64 * 64) + 240);
		str[1] = (char)((nbr / (64 * 64)) % 64 + 128);
		str[2] = (char)((nbr / 64) % 64 + 128);
	}
	str[ft_strlen(str)] = (char)(nbr % 64 + 128);
	return (str);
}

char	*ft_werror(char **buff, char **str)
{
	ft_strdel(buff);
	ft_strdel(str);
	return (NULL);
}
