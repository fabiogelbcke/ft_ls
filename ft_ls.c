/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 21:10:26 by fschuber          #+#    #+#             */
/*   Updated: 2015/06/12 21:53:04 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			handle_args(int ac, char **av, int *options, int *has_printed)
{
	int			i;
	int			j;
	char		**errors;
	t_node		*not_error;
	char		**dirs;

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
		not_error = is_file(av[i + options[6]], not_error, options, dirs);
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
	int			has_printed;

	i = -1;
	has_printed = 0;
	options = get_options(ac, av);
	dirs = (char**)malloc(sizeof(char*) * ac);
	if (!dirs)
		return (1);
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
