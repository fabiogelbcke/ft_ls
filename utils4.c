/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 23:51:19 by fschuber          #+#    #+#             */
/*   Updated: 2015/06/13 00:16:40 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_size_5(t_node *no, long *size_5)
{
	if (getpwuid(no->info.st_uid)
		&& *size_5 < ft_strlen(getpwuid(no->info.st_uid)->pw_name))
		*size_5 = ft_strlen(getpwuid(no->info.st_uid)->pw_name);
	else if (*size_5 < ft_strlen(ft_llitoa(no->info.st_uid)))
		*size_5 = ft_strlen(ft_llitoa(no->info.st_uid));
}

void	set_options(int *options, char c, int *j, char *str)
{
	if (!(ft_strrchr("lRart1sT", c) ||
		!ft_strcmp(str, "--")))
	{
		options[0] = -1;
		options[1] = c;
	}
	else if (c == 'l' || c == '1')
		options[0] = (c == 'l') ? 1 : 0;
	else if (c == 'R')
		options[1] = 1;
	else if (c == 'a')
		options[2] = 1;
	else if (c == 'r')
		options[3] = 1;
	else if (c == 't')
		options[4] = 1;
	else if (c == 's')
		options[5] = 1;
	else if (c == 'T')
		options[7] = 1;
	(*j)++;
}
