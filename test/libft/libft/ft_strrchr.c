/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 20:45:38 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/28 19:59:18 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char*)s;
	while (*ptr)
		ptr++;
	while (ptr != (char*)s)
	{
		if (*ptr == c)
			return (ptr);
		ptr--;
	}
	if (*ptr == c)
		return (ptr);
	return (NULL);
}
