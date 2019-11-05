/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:42:52 by obanshee          #+#    #+#             */
/*   Updated: 2019/09/25 13:05:28 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*point;

	while (*s)
	{
		if (*s == (char)c)
		{
			point = (char*)s;
			return (point);
		}
		s++;
	}
	if (*s == (char)c)
	{
		point = (char*)s;
		return (point);
	}
	return (NULL);
}
