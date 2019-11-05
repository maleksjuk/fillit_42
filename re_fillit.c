/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:53:02 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/05 13:48:44 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**RESULT_GLOBAL;

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
	int			len;

	if (!RESULT_GLOBAL)
		RESULT_GLOBAL = new_map(ft_strlen(*map) + 1);
	len = without_points(map, ft_strlen(*map));
	if (ft_strlen(*map) < ft_strlen(*RESULT_GLOBAL))
	{
		free_map(RESULT_GLOBAL, ft_strlen(*RESULT_GLOBAL));
		RESULT_GLOBAL = new_map(len);
		copy_map(map, RESULT_GLOBAL);
	}
	return (RESULT_GLOBAL);
}

char	**recur(char **map, char tetrimino[26][5][5], int nbr, int ins)
{
	int	i;
	int	j;

	if (ins == nbr)
		return (check_min(map));
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (insert_tetremino(map, tetrimino[ins], i, j))
			{
				recur(map, tetrimino, nbr, ins + 1);
				delete_tetra(map, ins);
			}
			i++;
		}
		j++;
	}
	return (NULL);
}

int		size_map(int nbr)
{
	int	size;

	size = 2;
	while (size * size < 4 * nbr)
		size++;
	return (size);
}

void	solve(char tetrimino[26][5][5], int nbr)
{
	char	**map;
	char	**result;
	int		size;
	int		k;

	size = size_map(nbr);
	map = new_map(size);
	result = recur(map, tetrimino, nbr, 0);
	while (!result)
	{
		free_map(map, size);
		size++;
		map = new_map(size);
		result = recur(map, tetrimino, nbr, 0);
		if (RESULT_GLOBAL)
			break ;
	}
	print_res(RESULT_GLOBAL);
}