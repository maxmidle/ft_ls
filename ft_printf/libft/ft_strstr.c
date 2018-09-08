/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radler <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:46:30 by radler            #+#    #+#             */
/*   Updated: 2017/11/17 21:16:11 by radler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!needle[0])
		return ((char *)&haystack[i]);
	while (haystack[i])
	{
		if (haystack[i] == needle[y])
			y++;
		else
			y = 0;
		if (needle[y] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
