/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:53:02 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/01 20:54:24 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		without_points(char **map, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		if (map[i][len - 1] != '.')
			return (len);
		if (map[len - 1][i] != '.')
			return (len);
		i++;
	}
	i = 0;
	while (i < len)
	{
		map[i][len - 1] = '\0';
		map[len - 1][i] = '\0';
		i++;
	}
	return (without_points(map, len - 1));
}

void	copy_map(char **map, char **res)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			res[i][j] = map[i][j];
			j++;
		}
		i++;
	}
}

char	**check_min(char **map)
{
	static char	**res;
	int			len;

	if (!res)
		res = new_map(ft_strlen(*map) + 1);
	len = without_points(map, ft_strlen(*map));
	if (ft_strlen(*map) < ft_strlen(*res))
	{
		free_map(res, ft_strlen(*res));
		res = new_map(len);
		copy_map(map, res);
	}
	return (res);
}

char	**recur(char **map, char tetrimino[26][5][5], int nbr, int ins)
{
	int		k;
	char	**res;

	if (ins == nbr)
		return (check_min(map));
	k = 0;
	while (k < nbr)
	{
		if (!search_tetra(map, k + 'A'))
		{
			if (insert_tetremino(map, tetrimino[k]))
				return (NULL);
			if (!res)
				res = new_map(ft_strlen(*map));
			if (!recur(map, tetrimino, nbr, ins + 1))
				delete_tetra(map, k);
		}
		k++;
	}
	return (NULL);
}

void	solve(char tetrimino[26][5][5], int nbr)
{
	char	**map;
	char	**result;
	int		size;
	int		k;

	size = 2;
	map = new_map(size);
	result = recur(map, tetrimino, nbr, 0);
	while (!result)
	{
		free_map(map, size);
		size++;
		map = new_map(size);
		result = recur(map, tetrimino, nbr, 0);
	}
	print_res(result);
}