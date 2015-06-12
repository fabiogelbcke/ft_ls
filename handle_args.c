/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 21:57:28 by fschuber          #+#    #+#             */
/*   Updated: 2015/06/12 22:45:22 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				is_error(char *str, int *options)
{
	DIR			*directory;
	t_node		*list;
	char		*name;
	char		*path;

	if (opendir(str) || !ft_strcmp("./", str) || !ft_strcmp("/", str))
		return (0);
	path = ft_strdup(str);
	name = ft_strdup(str);
	if (strrchr(path, '/'))
	{
		name = strrchr(path, '/');
		*(name++) = '\0';
	}
	path = (strrchr(path, '/')) ? ft_strjoin(path, "/") : ft_strdup(".");
	directory = opendir(path);
	list = get_list(directory, ft_strjoin(path, "/"), options);
	while (list)
	{
		if (!ft_cmpnocase(str, list->name) || !ft_cmpnocase(name, list->name))
			return (0);
		list = list->next;
	}
	return (1);
}

t_node			*is_file(char *str, t_node *list, int *options, char **dirs)
{
	DIR			*directory;
	t_node		*ptr;
	t_node		*curr;
	char		*path;
	char		*name;

	path = ft_strdup(str);
	name = ft_strdup(str);
	if (!ft_strcmp("./", str) || !ft_strcmp("/", str))
	{
		add_dir(str, dirs);
		return (list);
	}
	if (strrchr(path, '/'))
	{
		name = strrchr(path, '/');
		*(name++) = '\0';
		path = ft_strjoin(path, "/");
	}
	else
		path = ft_strdup(".");
	ptr = list;
	directory = opendir(path);
	curr = get_list(directory, ft_strjoin(path, "/"), options);
	while (curr)
	{
		curr->str = ft_strdup(str);
		curr->path = path;
		if (!ft_cmpnocase(str, curr->name) || !ft_cmpnocase(name, curr->name))
		{
			if ((options[0] == 0 && ((curr->linkinfo.st_mode)
				&& (curr->linkinfo.st_mode & S_IFDIR))) || (opendir(str)
				&& curr->data->d_type == DT_DIR))
				add_dir(str, dirs);
			else if (list)
			{
				while (list->next)
					list = list->next;
				list->next = curr;
				curr->next = NULL;
				return (ptr);
			}
			else
			{
				list = curr;
				list->next = NULL;
				return (list);
			}
		}
		curr = curr->next;
	}
	return (list);
}

void			print_errors(char **errors, int *has_printed)
{
	int			i;
	int			fakeoptions[6];

	fakeoptions[3] = 0;
	i = 0;
	if (errors[0] && errors[1])
		sort_dirs(errors, fakeoptions);
	while (errors[i])
	{
		errno = 2;
		ft_putstr("ls: ");
		if (ft_strlen(errors[i]) == 0)
		{
			ft_putstr("fts_open: ");
			perror(errors[i]);
			exit(1);
		}
		else
			perror(errors[i]);
		i++;
	}
}

void			print_files(t_node *list, int *options, int *has_printed)
{
	t_node		*ptr;

	ptr = list;
	if (options[4])
		sort_by_time_modified(list, NULL);
	while (ptr)
	{
		if (options[0] == 0)
		{
			ft_putstr(ptr->name);
			ft_putstr("\n");
		}
		else
			print_long(ptr, get_sizes(list, options), options, ptr->path);
		*has_printed = 1;
		if (errno == 13)
		{
			ft_putstr("oi");
			perror(ft_strjoin("ls: ", ptr->name));
		}
		ptr = ptr->next;
	}
}

void			print_dirs(int ac, char **dirs, int *options, int *has_printed)
{
	if (dirs && *dirs)
	{
		if (options[6] + 1 == ac)
			ls_directory(dirs[0], options, has_printed);
		else
			ls_directories(dirs, options, has_printed);
	}
}
