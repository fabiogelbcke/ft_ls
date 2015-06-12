/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 08:40:38 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/28 20:33:49 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	i = 0;
	if (!s || !f || !*f)
		return (NULL);
	while (s[i])
	{
		i++;
	}
	ret = (char*)malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = (*f)(s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
