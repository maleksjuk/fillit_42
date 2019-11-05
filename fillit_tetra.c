/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:54:34 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/05 16:56:49 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_insert(char **map, char tetrimino[5][5], int x, int y)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(*map);
	i = 0;
	j = 0;
	while (tetrimino[j][i])
	{
		while (tetrimino[j][i])
		{
			if ((y + j >= len) || (x + i >= len))
				return (0);
			if (tetrimino[j][i] != '.' && map[y + j][x + i] != '.')
				return (0);
			i++;
		}
		j++;
		i = 0;
	}
	return (1);
}

int		insert_tetremino(char **map, char tetrimino[5][5], int x, int y)
{
	int	i;
	int	j;

	if (!check_insert(map, tetrimino, x, y))
		return (0);
	i = 0;
	j = 0;
	while (tetrimino[j][i])
	{
		while (tetrimino[j][i])
		{
			if (tetrimino[j][i] != '.')
				map[j + y][i + x] = tetrimino[j][i];
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int		delete_tetra(char **map, int cur)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == cur + 'A')
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (1);
}

int		search_tetra(char **map, char cur)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == cur)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
