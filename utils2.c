/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 21:12:57 by fschuber          #+#    #+#             */
/*   Updated: 2015/06/13 00:34:50 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ls_directory(char *name, int *options, int *has_printed)
{
	DIR			*directory;
	t_node		*list;
	char		**dir_list;
	int			items;
	char		*path;

	directory = opendir(name);
	if (!directory)
	{
		perror("ft_ls:");
		return ;
	}
	path = (name[0] != '/' && name[0] != '~') ?
		ft_strjoin(ft_strjoin("./", name), "/") : ft_strjoin(name, "/");
	list = get_list(directory, path, options);
	items = print_list(list, options, path);
	*has_printed = 1;
	if (options[1])
	{
		closedir(directory);
		directory = opendir(name);
		dir_list = get_dirs(directory, ft_strjoin(ft_strjoin("./", name), "/")
				, items, options);
		ls_directories(dir_list, options, has_printed);
	}
}

void			sort_dirs(char **dirs, int *options)
{
	int			i;
	char		*temp;

	i = 0;
	while (dirs[i] && dirs[i + 1])
	{
		if ((ft_strcmp(dirs[i], dirs[i + 1]) > 0 && options[3] == 0)
			|| (ft_strcmp(dirs[i], dirs[i + 1]) < 0 && options[3] == 1))
		{
			temp = (dirs[i + 1]);
			dirs[i + 1] = (dirs[i]);
			dirs[i] = (temp);
			i = 0;
		}
		else
			i++;
	}
	dirs[i + 1] = NULL;
}

int				correct_str(char **dirs, int i)
{
	if (ft_strstr(dirs[i], "././"))
	{
		dirs[i] = &(dirs[i][2]);
		return (1);
	}
	else if (ft_strstr(dirs[i], ft_strjoin("./", "/")))
	{
		dirs[i] = &(dirs[i][2]);
		return (1);
	}
	return (0);
}

void			ls_directories(char **dirs, int *options, int *has_printed)
{
	int			i;

	i = 0;
	if (dirs[1] != NULL)
		sort_dirs(dirs, options);
	while (dirs[i])
	{
		if (*has_printed == 1)
			ft_putstr("\n");
		while (correct_str(dirs, i))
			i = i;
		ft_putstr(dirs[i]);
		ft_putendl(":");
		*has_printed = 1;
		ls_directory(dirs[i], options, has_printed);
		i++;
	}
}

void			device_or_size(char c, t_node *no)
{
	if (c == 'c' || c == 'b')
	{
		ft_putnbr(major(no->info.st_rdev));
		ft_putstr(ft_strjoin(",  ", ft_itoa(minor(no->info.st_rdev))));
	}
	else
		ft_putnbr(no->info.st_size);
}
