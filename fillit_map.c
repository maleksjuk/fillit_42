/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:42:52 by chbeast           #+#    #+#             */
/*   Updated: 2019/11/05 23:30:25 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**new_map(int size)
{
	int		i;
	int		j;
	char	**map;

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
		ft_putendl(map[i]);
		i++;
	}
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

int		size_map(int nbr)
{
	int	size;

	size = 2;
	while (size * size < 4 * nbr)
		size++;
	return (size);
}
