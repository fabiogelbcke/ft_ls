/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 18:36:02 by fschuber          #+#    #+#             */
/*   Updated: 2015/06/09 19:40:49 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				*get_options(int ac, char **av)
{
    int			i;
    int			j;
	int			*options;

	options = malloc(sizeof(int) * 8);
	i = 0;
	while (i < 8)
		options[i++] = 0;
	i = 1;
	while (i < ac && av[i][0] == '-' && ft_strlen(av[i]) > 1)
	{
		j = 1;
		while (av[i][j])
		{
			if (!(ft_strrchr("lRart1sT", av[i][j]) ||
				  !ft_strcmp(av[i], "--")))
			{
				options[0] = -1;
				options[1] = av[1][j];
				return (options);
			}
			if (av[i][j] == 'l')
				options[0] = 1;
			else if (av[i][j] == 'R')
				options[1] = 1;
			else if (av[i][j] == 'a')
				options[2] = 1;
			else if (av[i][j] == 'r')
				options[3] = 1;
			else if (av[i][j] == 't')
				options[4] = 1;
			else if (av[i][j] == 's')
				options[5] = 1;
			else if (av[i][j] == 'T')
				options[7] = 1;
			j++;
		}
		i++;
		if (!ft_strcmp(av[i - 1], "--"))
			break ;
	}
	options[6] = i;
	return (options);
}

void			put_spaces(int n)
{
	int			i;

	i = 0;
	while (i++ < n)
		ft_putchar(' ');
}

char			get_type(t_node *no)
{
	if (no->data->d_type == DT_LNK)
		return ('l');
	if (S_ISBLK(no->info.st_mode))
		return ('b');
	else if (no->info.st_mode & S_IFCHR)
		return ('c');
	else if (S_ISSOCK(no->info.st_mode))
		return ('s');
	else if (no->info.st_mode & S_IFIFO)
		return ('p');
	else if (no->info.st_mode & S_IFDIR)
		return ('d');
	return ('-');
}
