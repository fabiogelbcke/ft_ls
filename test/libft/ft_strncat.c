/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 19:17:02 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/28 19:51:59 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s1ptr;
	int		i;

	i = 0;
	s1ptr = s1;
	while (*s1ptr)
		s1ptr++;
	while (*s2 && i < (int)n)
	{
		*(s1ptr++) = *(s2++);
		i++;
	}
	*s1ptr = '\0';
	return (s1);
}
