/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:23:06 by obanshee          #+#    #+#             */
/*   Updated: 2019/09/25 13:05:08 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*point;

	point = s1;
	while (*s1)
		s1++;
	i = 0;
	while (*s2 && i < n)
	{
		*s1 = *s2;
		i++;
		s2++;
		s1++;
	}
	*s1 = '\0';
	return (point);
}
