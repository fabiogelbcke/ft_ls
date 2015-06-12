/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 14:26:39 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/28 19:24:19 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isspace(char c)
{
	if (c == '\n' || c == ' ' || c == '\v' ||
			c == '\t' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

static void		changevalues(long int *num, long int *factor, char *ptr)
{
	*num = (*num) + ((*ptr - 48) * (*factor));
	*factor = (*factor) * 10;
}

int				ft_atoi(const char *str)
{
	char		*ptr;
	long int	num;
	long int	factor;
	int			isneg;

	if (!str)
		return (0);
	ptr = (char*)str;
	num = 0;
	factor = 1;
	isneg = 1;
	while (isspace(*ptr))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			isneg = -1;
		ptr++;
	}
	while (*ptr >= 48 && *ptr <= 57)
		ptr++;
	ptr--;
	while (*ptr >= 48 && *ptr <= 57)
		changevalues(&num, &factor, ptr--);
	return (num * isneg);
}
