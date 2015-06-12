/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 20:50:00 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/28 20:35:24 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		length;
	char		*out;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	out = NULL;
	if ((start + len) <= length)
	{
		out = (char*)malloc(sizeof(char) * (len + 1));
		if (out)
		{
			out = ft_strncpy(out, s + start, len);
			out[len] = '\0';
		}
	}
	return (out);
}
