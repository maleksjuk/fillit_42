/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:35:53 by obanshee          #+#    #+#             */
/*   Updated: 2019/09/25 13:06:53 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	helper(int flag, int i, int num)
{
	if (flag)
		num = num * (-1);
	if (i > 18)
	{
		if (!flag)
			return (-1);
		else
			return (0);
	}
	return (num);
}

int			ft_atoi(const char *str)
{
	int	num;
	int	flag;
	int	i;

	num = 0;
	flag = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		flag = 1;
	if (*str == '-' || *str == '+')
		str++;
	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
		i++;
	}
	i = helper(flag, i, num);
	return (i);
}
