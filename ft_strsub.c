/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:54:33 by obanshee          #+#    #+#             */
/*   Updated: 2019/09/25 14:25:02 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	while (start)
	{
		s++;
		start--;
	}
	if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	sub[len] = '\0';
	while (i < len)
	{
		sub[i] = *s;
		s++;
		i++;
	}
	return (sub);
}
