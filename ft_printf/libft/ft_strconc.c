/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radler <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 09:25:30 by radler            #+#    #+#             */
/*   Updated: 2018/05/01 11:17:05 by radler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strconc(char **s1, char *s2)
{
	char *tmp;

	tmp = ft_strdup(*s1);
	free(*s1);
	*s1 = ft_strjoin(tmp, s2);
	free(tmp);
}
