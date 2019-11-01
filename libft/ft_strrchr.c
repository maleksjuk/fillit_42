/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:25:46 by obanshee          #+#    #+#             */
/*   Updated: 2019/09/25 13:05:43 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*point;

	point = NULL;
	while (*s)
	{
		if (*s == (char)c)
			point = (char*)s;
		s++;
	}
	if (*s == (char)c)
		point = (char*)s;
	if (point)
		return (point);
	return (NULL);
}
