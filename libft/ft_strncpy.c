/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 18:36:27 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/21 03:37:50 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int i;

	i = 0;
	while (i < (int)n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < (int)n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
