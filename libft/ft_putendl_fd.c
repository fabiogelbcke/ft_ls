/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 03:07:37 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/28 19:35:28 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putendl_fd(char const *s, int fd)
{
	char	*ptr;
	int		size;

	if (!s)
		return ;
	size = 0;
	ptr = (char*)s;
	while (*ptr)
	{
		size++;
		ptr++;
	}
	write(fd, s, size);
	write(fd, "\n", 1);
}
