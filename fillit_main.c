/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:31:17 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/06 20:12:04 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit_usage(void)
{
	write(1, "usage: ./fillit [file_input]\n\tuse 1 file to input\n", 50);
	return (0);
}

void	tetra_null(char tetrimino[26][5][5])
{
	int	i;
	int	j;
	int	cur;

	cur = 0;
	while (cur < 26)
	{
		j = 0;
		while (j < 5)
		{
			i = 0;
			while (i < 5)
			{
				tetrimino[cur][j][i] = '\0';
				i++;
			}
			j++;
		}
		cur++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	char	tetrimino[26][5][5];
	int		nbr;

	if (ac != 2)
		return (fillit_usage());
	tetra_null(tetrimino);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	nbr = fillit_input(fd, tetrimino);
	close(fd);
	if (nbr == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	solve(tetrimino, nbr);
	return (0);
}
