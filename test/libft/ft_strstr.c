/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 20:50:00 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/28 20:14:55 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strstr(const char *s1, const char *s2)
{
	char	*ptr1;
	char	*ptr2;
	char	*ptr3;

	if (!(s1) || !s2)
		return (NULL);
	if (!(*s1) && (!*s2))
		return ((char*)s1);
	ptr3 = (char*)s1;
	while (*ptr3)
	{
		ptr1 = (char*)ptr3;
		ptr2 = (char*)s2;
		while (*ptr2 && *ptr1)
		{
			if (*ptr1 != *ptr2)
				break ;
			ptr1++;
			ptr2++;
		}
		if (!(*ptr2))
			return ((char*)ptr3);
		ptr3++;
	}
	return (NULL);
}
