/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:53:02 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/05 16:56:35 by obanshee         ###   ########.fr       */
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

char	**check_min(char **map)
{
	int	len;

	if (!g_result)
		g_result = new_map(ft_strlen(*map) + 1);
	len = without_points(map, ft_strlen(*map));
	if (ft_strlen(*map) < ft_strlen(*g_result))
	{
		free_map(g_result, ft_strlen(*g_result));
		g_result = new_map(len);
		copy_map(map, g_result);
	}
	return (g_result);
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
		if (g_result)
			break ;
	}
	print_res(g_result);
}
