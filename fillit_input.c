/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:00:32 by obanshee          #+#    #+#             */
/*   Updated: 2019/10/29 21:38:11 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"

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
	if (ft_strlen(line) != 4)
		return (1);
	return (0);
}

int	finish_input(int cur, int gnl)
{
	if (gnl < 0)
		return (0);
	return (cur);
}

int	fillit_input(int fd, char tetrimino[26][5][5])
{
	int		gnl;
	char	*line;
	char	cur;
	int		num_str;

	cur = 'A';
	gnl = get_next_line(fd, &line);
	num_str = 0;
	while (gnl > 0)
	{
		if (input_check(line) || transform(cur - 'A', line, tetrimino, num_str))
			return (0);
		free(line);
		gnl = get_next_line(fd, &line);
		num_str++;
		if (num_str == 4)
		{
			num_str = 0;
			cur++;
			if ((cur == 'Z' + 1) || !ft_strequ(line, ""))
				return (0);
			gnl = get_next_line(fd, &line);
		}
	}
	return (finish_input(cur - 'A', gnl));
}
