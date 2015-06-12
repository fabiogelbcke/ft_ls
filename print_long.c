/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 16:29:40 by fschuber          #+#    #+#             */
/*   Updated: 2015/06/12 20:09:14 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_permissions(t_node *no, int size_links, char *path)
{
	int		i;

	i = size_links + 2 - ft_strlen(ft_itoa(no->info.st_nlink));
	ft_putchar(get_type(no, path));
	ft_putstr((no->info.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((no->info.st_mode & S_IWUSR) ? "w" : "-");
	if (no->info.st_mode & S_ISUID)
		ft_putstr((no->info.st_mode & S_IXUSR) ? "s" : "S");
	else
		ft_putstr((no->info.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((no->info.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((no->info.st_mode & S_IWGRP) ? "w" : "-");
	if (no->info.st_mode & S_ISGID)
		ft_putstr((no->info.st_mode & S_IXUSR) ? "s" : "S");
	else
		ft_putstr((no->info.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((no->info.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((no->info.st_mode & S_IWOTH) ? "w" : "-");
	if (no->info.st_mode & S_ISVTX)
		ft_putstr((no->info.st_mode & S_IXOTH) ? "t" : "T");
	else
		ft_putstr((no->info.st_mode & S_IXOTH) ? "x" : "-");
	if (no->extattr && i--)
		ft_putchar('@');
	while (i-- > 0)
		ft_putchar(' ');
}

char		*remove_extra_spaces(char *str)
{
	int		i;
	char	*newstr;
	int		j;

	i = 0;
	j = 0;
	newstr = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		if (str[i] != '\n'
			&& (i < 15 || str[i] != ' ' || str[i + 1] != ' '))
			newstr[j++] = str[i];
		i++;
	}
	newstr[j] = '\0';
	return (newstr);
}

void		print_time(t_node *no, int *options)
{
	char	*timestr;
	char	*todaystr;
	time_t	sectoday;
	time_t	sec;

	sec = no->info.st_mtimespec.tv_sec;
	timestr = malloc(sizeof(char) * 27);
	timestr = ft_strcpy(timestr, ctime(&sec));
	if (options[7] == 1)
	{
		ft_putstr(ft_strjoin(ft_strsub(timestr, 4, 20), " "));
		return ;
	}
	timestr = remove_extra_spaces(timestr);
	time(&sectoday);
	todaystr = ctime(&sectoday);
	ft_putstr(ft_strsub(timestr, 4, 6));
	if ((ft_strcmp(ft_strsub(timestr, 20, 4), ft_strsub(todaystr, 20, 4))
		&& (sectoday - sec > 15768000)) || sec > sectoday)
		ft_putstr(ft_strjoin("  ", ft_strsub(timestr, 20
										, ft_strlen(timestr) - 20)));
	else
		ft_putstr(ft_strjoin(" ", ft_strsub(timestr, 11, 5)));
	ft_putchar(' ');
}

void		print_acc_group_size(t_node *no, long *sizes, char *path)
{
	int		i;
	char	c;

	i = (getpwuid(no->info.st_uid)) ? ft_strlen(getpwuid(no->info.st_uid)->pw_name)
		: ft_strlen(ft_itoa(no->info.st_uid));
	ft_putstr(" ");
	if (getpwuid(no->info.st_uid))
		ft_putstr(getpwuid(no->info.st_uid)->pw_name);
	else
		ft_putnbr(no->info.st_uid);
	put_spaces(sizes[5] - i + 2);
	if (getgrgid(no->info.st_gid))
		ft_putstr(getgrgid(no->info.st_gid)->gr_name);
	else
		ft_putnbr(no->info.st_gid);
	i = (getgrgid(no->info.st_gid)) ? ft_strlen(getgrgid(no->info.st_gid)->gr_name)
		: ft_strlen(ft_itoa(no->info.st_gid));
	put_spaces(sizes[3] - i + 2 + sizes[1] - ft_strlen(ft_itoa(no->info.st_size)));
	c = get_type(no, path);
	if (c == 'c' || c == 'b')
	{
		ft_putnbr(major(no->info.st_rdev));
		ft_putstr(",  ");
		ft_putnbr(minor(no->info.st_rdev));
	}
	else
		ft_putnbr(no->info.st_size);
	ft_putstr(" ");
}

void		print_long(t_node *no, long *sizes, int *options, char *path)
{
	print_permissions(no, sizes[0], path);
	ft_putnbr(no->info.st_nlink);
	print_acc_group_size(no, sizes, path);
	print_time(no, options);
	if (no->str)
		ft_putstr(no->str);
	else
		ft_putstr(no->name);
	print_link(no, path);
	ft_putchar('\n');
}
