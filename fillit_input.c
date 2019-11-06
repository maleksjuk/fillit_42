/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:00:32 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/06 22:37:58 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	input_check(char *line)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (line[i] != '.')
			if (line[i] != '#')
				return (1);
		i++;
	}
	if (line[4] != '\n')
		return (1);
	line[4] = '\0';
	if (ft_strlen(line) != 4)
		return (1);
	return (0);
}

int	finish_input(int cur, int gnl, int num_str, char *line)
{
	free_line(line);
	if (gnl < 0 || num_str == 0)
		return (0);
	if (gnl == 0 && num_str != 4)
		return (0);
	else
		cur++;
	return (cur);
}

int	free_line(char *line)
{
	if (line && *line)
		free(line);
	return (0);
}

int	reader(int fd, char *line)
{
	char	bufer[2];
	int		ret;
	int		i;

	i = 0;
	ret = read(fd, bufer, 1);
	while (ret > 0)
	{
		line[i] = bufer[0];
		i++;
		if (bufer[0] == '\n')
			return (1);
		ret = read(fd, bufer, 1);
	}
	if (ret < 0)
		return (-1);
	return (0);
}

int	fillit_input(int fd, char tetrimino[26][5][5])
{
	int		ret;
	char	*line;
	char	cur;
	int		num_str;

	cur = 'A';
	line = ft_strnew(4);
	num_str = 0;
	ret = reader(fd, line);
	while (ret > 0)
	{
		if (input_check(line) || transform(cur - 'A', line, tetrimino, num_str))
			return (free_line(line));
		ret = reader(fd, line);
		num_str++;
		if (ret > 0 && num_str == 4)
		{
			num_str = 0;
			cur++;
			if (cur > 'Z' || line[0] != '\n')
				return (free_line(line));
			ret = reader(fd, line);
		}
	}
	return (finish_input(cur - 'A', ret, num_str, line));
}
