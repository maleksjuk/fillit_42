/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_optimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:50:50 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/05 17:22:14 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit_swap_left(int cur, char tetrimino[26][5][5])
{
	int	j;

	j = 0;
	while (j < 4)
	{
		if (tetrimino[cur][j][0] != '.')
			break ;
		j++;
	}
	if (j == 4)
	{
		j = 0;
		while (j < 4)
		{
			tetrimino[cur][j][0] = tetrimino[cur][j][1];
			tetrimino[cur][j][1] = tetrimino[cur][j][2];
			tetrimino[cur][j][2] = tetrimino[cur][j][3];
			tetrimino[cur][j][3] = '.';
			j++;
		}
		fillit_swap_left(cur, tetrimino);
	}
}

void	fillit_swap_top(int cur, char tetrimino[26][5][5])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tetrimino[cur][0][i] != '.')
			break ;
		i++;
	}
	if (i == 4)
	{
		i = 0;
		while (i < 4)
		{
			tetrimino[cur][0][i] = tetrimino[cur][1][i];
			tetrimino[cur][1][i] = tetrimino[cur][2][i];
			tetrimino[cur][2][i] = tetrimino[cur][3][i];
			tetrimino[cur][3][i] = '.';
			i++;
		}
		fillit_swap_top(cur, tetrimino);
	}
}

int		without_points_right(int cur, char tetrimino[26][5][5], int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (tetrimino[cur][i][len] == cur + 'A')
			return (len);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (tetrimino[cur][i][len] == '.')
			tetrimino[cur][i][len] = '\0';
		i++;
	}
	return (without_points_right(cur, tetrimino, len - 1));
}

int		without_points_bottom(int cur, char tetrimino[26][5][5], int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (tetrimino[cur][len][i] == cur + 'A')
			return (len);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (tetrimino[cur][len][i] == '.')
			tetrimino[cur][len][i] = '\0';
		i++;
	}
	return (without_points_bottom(cur, tetrimino, len - 1));
}

void	fillit_optimal(int cur, char tetrimino[26][5][5])
{
	int	len_cur;

	fillit_swap_left(cur, tetrimino);
	fillit_swap_top(cur, tetrimino);
	len_cur = without_points_right(cur, tetrimino, 4);
	len_cur = without_points_bottom(cur, tetrimino, 4);
}
