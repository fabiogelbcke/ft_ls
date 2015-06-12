/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 07:58:46 by fschuber          #+#    #+#             */
/*   Updated: 2014/12/01 16:07:23 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		numtostr(char **strptr, long int n, long int size)
{
	char		*str;

	str = *strptr;
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	str[size] = '\0';
	while (n > 0)
	{
		str[size - 1] = '0' + (char)(n % 10);
		n = n / 10;
		size--;
	}
}

char			*ft_itoa(int n)
{
	char		*str;
	int			size;
	long int	temp;

	size = 0;
	temp = n;
	if (n < 0)
	{
		size++;
		temp = temp * -1;
	}
	while (temp > 0)
	{
		temp = temp / 10;
		size++;
	}
	if (n == 0)
		size = 1;
	str = (char*)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	numtostr(&str, n, size);
	return (str);
}
