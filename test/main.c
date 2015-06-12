/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 17:31:49 by fschuber          #+#    #+#             */
/*   Updated: 2015/06/12 17:36:06 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd1 = open("sysls", O_RDONLY);
	int fd2 = open("myls", O_RDONLY);
	char *line1;
	char *line2;
	int r1 = 1;
	int r2 = 1;

	while (r1 > 0 && r2 > 0)
	{
		r1 = get_next_line(fd1, &line1);
		r2 = get_next_line(fd2, &line2);
		if (!ft_strcmp(line1, line2))
		{
			ft_putstr(line1);
			ft_putstr("\n");
			ft_putstr(line2);
			ft_putstr("\n\n");
		}
	}
	return (0);
}
