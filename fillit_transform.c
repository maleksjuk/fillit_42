/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:13:11 by obanshee          #+#    #+#             */
/*   Updated: 2019/10/23 20:48:16 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"

int	sv_func(int cur, char tetrimino[26][5][5], int i, int j)
{
	int	sv;

	sv = 0;
	if (tetrimino[cur][j][i + 1] == cur + 'A')
		sv++;
	if (tetrimino[cur][j][i - 1] == cur + 'A')
		sv++;
	if (tetrimino[cur][j + 1][i] == cur + 'A')
		sv++;
	if (tetrimino[cur][j - 1][i] == cur + 'A')
		sv++;
	return (sv);
}

int	tetra_check(int cur, char tetrimino[26][5][5])
{
	int	i;
	int	j;
	int	count;
	int	sv;

	sv = 0;
	count = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetrimino[cur][j][i] == cur + 'A')
			{
				count++;
				sv = sv + sv_func(cur, tetrimino, i, j);
			}
			i++;
		}
		j++;
	}
	if (count != 4 || (sv != 6 && sv != 8))
		return (1);
	return (0);
}

int	transform(int cur, char *line, char tetrimino[26][5][5], int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (line[i] == '#')
			tetrimino[cur][num][i] = cur + 'A';
		else
			tetrimino[cur][num][i] = '.';
		i++;
	}
	tetrimino[cur][num][i] = '\0';
	if (num == 3)
	{
		if (tetra_check(cur, tetrimino))
			return (1);
		fillit_optimal(cur, tetrimino);
	}
	return (0);
}
