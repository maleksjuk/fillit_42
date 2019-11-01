/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:47:25 by obanshee          #+#    #+#             */
/*   Updated: 2019/09/25 13:06:12 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*point;
	size_t	i;
	size_t	n;
	size_t	j;

	n = 0;
	while (needle[n])
		n++;
	if (len == 0 && n != 0)
		return (NULL);
	j = 0;
	while ((*haystack && j < len) || !len)
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i] && haystack[i])
			i++;
		if (i == n && i <= len - j)
		{
			point = (char*)haystack;
			return (point);
		}
		haystack++;
		j++;
	}
	return (NULL);
}
