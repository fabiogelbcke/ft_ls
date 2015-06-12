/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 13:40:40 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/28 19:32:10 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ptr;
	void	*srcptr;
	int		i;

	ptr = dst;
	srcptr = (void*)src;
	i = 0;
	while (i < (int)n)
	{
		*((char*)ptr) = *((char*)srcptr);
		ptr++;
		srcptr++;
		i++;
	}
	return (dst);
}
