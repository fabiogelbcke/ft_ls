/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 07:33:33 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/28 19:52:52 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	str = (char*)malloc(((int)size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < (int)size)
	{
		str[i] = 0;
		i++;
	}
	str[i] = '\0';
	return (str);
}
