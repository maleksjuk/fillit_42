/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:58:40 by obanshee          #+#    #+#             */
/*   Updated: 2019/09/25 14:33:07 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (len && (s[len - 1] == ' ' || s[len - 1] == '\t' ||
				s[len - 1] == '\n'))
		len--;
	while (len && (*s == ' ' || *s == '\t' || *s == '\n'))
	{
		s++;
		len--;
	}
	str = ft_strnew(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i++] = *s;
		s++;
	}
	return (str);
}
