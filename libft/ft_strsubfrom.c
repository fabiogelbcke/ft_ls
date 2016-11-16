/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfrom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 20:50:00 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/28 20:35:24 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsubfrom(char const *s, unsigned int start)
{
	size_t		length;
	char		*out;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	out = NULL;
	if (start >= length)
		return (NULL);
	out = (char*)malloc(sizeof(char) * (length + 1 - start));
	if (out)
	{
		out = ft_strncpy(out, s + start, length - start);
		out[length - start] = '\0';
	}
	return (out);
}
