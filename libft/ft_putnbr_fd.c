/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:35:37 by obanshee          #+#    #+#             */
/*   Updated: 2019/09/25 13:14:08 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_putnbr_fd(int n, int dec, int fd)
{
	char	c;

	if (n < 0)
	{
		c = '-';
		write(fd, &c, 1);
		n = n * (-1);
	}
	while (dec)
	{
		c = '0' + n / dec % 10;
		write(fd, &c, 1);
		dec = dec / 10;
	}
}

static void	print_min_fd(int fd)
{
	char	min[12];

	min[0] = '-';
	min[1] = '2';
	min[2] = '1';
	min[3] = '4';
	min[4] = '7';
	min[5] = '4';
	min[6] = '8';
	min[7] = '3';
	min[8] = '6';
	min[9] = '4';
	min[10] = '8';
	min[11] = '\0';
	write(fd, &min, 11);
}

void		ft_putnbr_fd(int n, int fd)
{
	int		nbr;
	int		dec;

	dec = 1;
	nbr = n;
	if (n == -2147483648)
	{
		print_min_fd(fd);
		return ;
	}
	while (nbr > 9 || nbr < -9)
	{
		nbr = nbr / 10;
		dec = dec * 10;
	}
	print_putnbr_fd(n, dec, fd);
}
