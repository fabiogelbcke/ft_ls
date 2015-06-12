/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 06:35:15 by fschuber          #+#    #+#             */
/*   Updated: 2014/12/01 16:12:44 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr;
	unsigned char	*ptrdst;
	unsigned char	*temp;
	int				i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	temp = (void*)malloc(len);
	ptr = (unsigned char*)src;
	while (i < (int)len)
	{
		temp[i] = ptr[i];
		i++;
	}
	i = 0;
	ptr = (unsigned char*)src;
	ptrdst = (unsigned char*)dst;
	while (i < (int)len)
	{
		ptrdst[i] = temp[i];
		i++;
	}
	return (dst);
}
