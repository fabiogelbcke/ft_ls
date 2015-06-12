/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 15:45:33 by fschuber          #+#    #+#             */
/*   Updated: 2015/06/09 20:57:27 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <string.h>

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
		ft_putstr("ft_ls: ");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
		return ;
	}
	if (name[0] != '/' && name[0] != '~')
		path = ft_strjoin(ft_strjoin("./", name), "/");
	else
	        path = ft_strjoin(name, "/");
	list = get_list(directory, path);
	list = sort_list(list, options);
	items = print_list(list, options, path);
	*has_printed = 1;
	if (options[1])
	{
		closedir(directory);
		directory = opendir(name);
		dir_list = get_dirs(directory, ft_strjoin(ft_strjoin("./", name), "/"), items, options);
		ls_directories(dir_list, options, has_printed);
	}
}

void			sort_dirs(char **dirs, int *options)
{
	int			i;
	char		*temp;
	char		*str1;
	char		*str3;

	i = 0;
	while (dirs[i] && dirs[i + 1])
	{
		str1 = ft_strdup(dirs[i]);
		str3 = ft_strdup(dirs[i + 1]);
		if ((ft_strcmp(str1, str3) > 0 && options[3] == 0)
		    ||(ft_strcmp(str1,str3) < 0 && options[3] == 1))
		{
			temp = ft_strdup(dirs[i + 1]);
			dirs[i + 1] = ft_strdup(dirs[i]);
			dirs[i] = ft_strdup(temp);
			i = 0;
		}
		else
			i++;
	}
	dirs[i + 1] = NULL;
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
		while (ft_strstr(dirs[i], "././"))
			dirs[i] += 2;
		ft_putstr(dirs[i]);
		ft_putstr(":");
		ft_putchar('\n');
		*has_printed = 1;
		ls_directory(dirs[i], options, has_printed);
		i++;
	}
}

void handle_args(int ac, char **av, int *options, int *has_printed)
{
	int i;
	int j;
	char **errors;
	t_node *not_error;
	char **dirs;

	i = -1;
	j = 0;
	errors = malloc(sizeof(char*) * ac);
	not_error = NULL;
	while (++i + options[6] < ac)
		if (is_error(av[i + options[6]], options))
			errors[j++] = ft_strdup(av[i + options[6]]);
	errors[j] = NULL;
	i = -1;
	dirs = malloc(sizeof(char*) * (ac));
	while (++i + options[6] < ac)
		not_error = is_file(av[i + options [6]], not_error, options, dirs);
	//dirs = dirs_table(ac, options, av);
	print_errors(errors, has_printed);
	if (not_error)
		not_error = sort_ascii(not_error);
	if (options[3])
		not_error = invert_list(not_error);
	print_files(not_error, options, has_printed);
	print_dirs(ac, dirs, options, has_printed);
}

int				main(int ac, char **av)
{
	int			*options;
	int			i;
	char		**dirs;
	int		has_printed;

	i = -1;
	has_printed = 0;
	options = get_options(ac, av);
	dirs = (char**)malloc(sizeof(char*) * ac);
	if (options[0] == -1)
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(options[1]);
		ft_putstr("\nusage: ./ft_ls [-lRart] [file ...]\n");
		write(2, "Illegal option", 14);
		return (1);
	}
	if (options[6] == ac)
		ls_directory(".", options, &has_printed);
	else
		handle_args(ac, av, options, &has_printed);
	return (0);
}
