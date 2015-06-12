/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 19:41:57 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/28 19:49:14 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*srcptr;
	int		i;
	int		len;

	srcptr = (char*)src;
	len = ft_strlen(dst);
	i = len;
	if ((int)size < len)
		return (size + ft_strlen(src));
	while (*srcptr != '\0' && i < (int)size - 1)
	{
		dst[i] = *srcptr;
		i++;
		srcptr++;
	}
	dst[i] = '\0';
	return (len + ft_strlen(src));
}
