/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:34:16 by obanshee          #+#    #+#             */
/*   Updated: 2019/09/25 13:05:14 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (len_d >= size)
		return (size + len_s);
	i = 0;
	while (*dst && i < size - 1)
	{
		dst++;
		i++;
	}
	while (*src && i < size - 1)
	{
		*dst = *src;
		i++;
		src++;
		dst++;
	}
	*dst = '\0';
	return (len_d + len_s);
}
