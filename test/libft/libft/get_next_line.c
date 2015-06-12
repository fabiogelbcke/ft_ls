/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 14:42:06 by fschuber          #+#    #+#             */
/*   Updated: 2015/04/29 17:19:24 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_realloc(char *ptr, size_t size)
{
	char	*dst;

	dst = ptr;
	dst += size - BUFF_SIZE;
	dst = (char*)malloc(BUFF_SIZE * sizeof(char));
	if (!dst)
		return (NULL);
	return (ptr);
}

void		ft_strccat(char *dst, const char *src, char c, int readbytes)
{
	dst += ft_strlen(dst);
	if (!ft_memchr(src, c, readbytes))
	{
		ft_memcpy(dst, src, readbytes);
		dst += readbytes;
		*dst = '\0';
	}
}

int			get_next_line(const int fd, char **line)
{
	char	buff[BUFF_SIZE];
	size_t	size;
	int		i;

	if (fd < 0 || !line || !*line)
		return (-1);
	size = BUFF_SIZE;
	*line = malloc(sizeof(char));
	*line[0] = '\0';
	while (1)
	{
		ft_strclr(buff);
		*line = ft_realloc(*line, size);
		if (!(*line))
			return (-1);
		i = -1;
		while (++i < BUFF_SIZE)
			if (read(fd, &(buff[i]), 1) != 1 || buff[i] == '\n')
				break ;
		ft_strccat(*line, buff, '\n', i);
		if (buff[i] == '\n' || i != BUFF_SIZE)
			return (buff[i] == '\n') ? 1 : 0;
		size += BUFF_SIZE;
	}
	return (-1);
}
