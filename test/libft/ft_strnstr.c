/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 04:14:20 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/28 20:27:13 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	int		i;
	int		k;

	i = 0;
	if ((!s1 || !s2) || (!(*s1) && !(*s2)))
		return (!s1 || !s2) ? NULL : ((char*)s1);
	while (s1[i] && i < (int)n)
	{
		k = 0;
		ptr1 = (char*)&(s1[i]);
		ptr2 = (char*)s2;
		while (*ptr1 && *ptr2 && i + k++ < (int)n)
		{
			if (*ptr1 != *ptr2)
				break ;
			ptr1++;
			ptr2++;
		}
		if (!(*ptr2))
			return ((char*)&(s1[i]));
		i++;
	}
	return (NULL);
}
