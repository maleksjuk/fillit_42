/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:31:38 by obanshee          #+#    #+#             */
/*   Updated: 2019/09/25 13:05:59 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*point;
	int		i;
	int		len;

	len = 0;
	while (needle[len])
		len++;
	while (*haystack || !len)
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i] && haystack[i])
			i++;
		if (i == len)
		{
			point = (char*)haystack;
			return (point);
		}
		haystack++;
	}
	return (NULL);
}
