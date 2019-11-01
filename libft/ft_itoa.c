/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:25:32 by obanshee          #+#    #+#             */
/*   Updated: 2019/09/25 13:12:36 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_digit(int n)
{
	int	len;

	len = 0;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

static char	*min_int(void)
{
	char	*str;

	if (!(str = ft_strnew(12)))
		return (NULL);
	*str = '-';
	*(str + 1) = '2';
	*(str + 2) = '1';
	*(str + 3) = '4';
	*(str + 4) = '7';
	*(str + 5) = '4';
	*(str + 6) = '8';
	*(str + 7) = '3';
	*(str + 8) = '6';
	*(str + 9) = '4';
	*(str + 10) = '8';
	*(str + 11) = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (min_int());
	len = len_digit(n);
	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	while ((len >= 0 && !str[0]) || (len > 0 && str[0]))
	{
		str[len] = '0' + n % 10;
		len--;
		n = n / 10;
	}
	return (str);
}
