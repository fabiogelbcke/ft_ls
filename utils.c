/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 18:36:02 by fschuber          #+#    #+#             */
/*   Updated: 2015/06/13 00:15:49 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				*get_options(int ac, char **av)
{
	int			i;
	int			j;
	int			*options;

	options = malloc(sizeof(int) * 8);
	ft_memset(options, 0, sizeof(int) * 8);
	i = 1;
	while (i < ac && av[i][0] == '-' && ft_strlen(av[i]) > 1)
	{
		j = 1;
		while (av[i][j])
		{
			set_options(options, av[i][j], &j, av[i]);
			if (!(ft_strrchr("lRart1sT", av[i][j]) ||
				!ft_strcmp(av[i], "--")))
				return (options);
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

char			get_type(t_node *no, char *path)
{
	char		buf[512];

	if (!ft_strcmp(".", path))
		path = ft_strdup("");
	if (readlink(ft_strjoin(path, no->name), buf, sizeof(buf)) != -1)
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

void			print_link(t_node *no, char *path)
{
	char		buf[1024];
	ssize_t		len;

	if (!ft_strcmp(".", path))
		path = ft_strdup("");
	len = readlink(ft_strjoin(path, no->name), buf, sizeof(buf));
	if (len == -1)
		return ;
	buf[len] = '\0';
	ft_putstr(" -> ");
	ft_putstr(buf);
}

void			add_dir(char *str, char **dirs)
{
	int			i;

	i = 0;
	while (dirs[i])
		i++;
	dirs[i] = ft_strdup(str);
	dirs[i + 1] = NULL;
}
