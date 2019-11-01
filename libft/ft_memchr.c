/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:54:32 by obanshee          #+#    #+#             */
/*   Updated: 2019/09/25 13:02:36 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*point;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)s == (unsigned char)c)
		{
			point = (char *)s;
			return (point);
		}
		s++;
		i++;
	}
	return (NULL);
}
