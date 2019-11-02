/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:42:52 by chbeast           #+#    #+#             */
/*   Updated: 2019/11/02 23:10:26 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**new_map(int size)
{
	int i;
	int j;
	char **map;

	j = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (j < size)
	{
		if (!(map[j] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		i = 0;
		while (i < size)
		{
			map[j][i] = '.';
			i++;
		}
		map[j][i] = '\0';
		j++;
	}
	map[j] = NULL;
	return (map);
}

void	print_res(char **map)
{
	int i;

	i = 0;
	if (!map)
	{
		ft_putendl("error");
		exit(0);
	}
	while (map[i])
	{
		printf("|>   %s\n", map[i]);
		i++;
	}
}

int		check_insert(char **map, char tetrimino[5][5], int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tetrimino[j][i])
	{
		while (tetrimino[j][i])
		{
			if (y + j >= ft_strlen(*map))
				return (0);
			if (x + i >= ft_strlen(*map))
				if (tetrimino[j][i] == '.')
					break ;
				else
					return (0);
			else if (tetrimino[j][i] != '.' && map[y + j][x + i] != '.')
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
	//int	x;
	//int	y;
	//int	k;

	//x = 0;
	//y = 0;
	//k = 0;
//	while (y != ft_strlen(*map))
/*	while (check_insert(map, tetrimino, x, y))
	{
	//	if (check_insert(map, tetrimino, x, y))
	//		k++;
		x++;
		if (x == ft_strlen(*map))
		{
			y++;
			x = 0;
		}
		if (y == ft_strlen(*map))
			return (0);
	}*/
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

void	free_map(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
