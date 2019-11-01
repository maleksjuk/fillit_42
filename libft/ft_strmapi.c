/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:23:23 by obanshee          #+#    #+#             */
/*   Updated: 2019/09/25 14:22:20 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*point;
	size_t	len;
	int		i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	point = str;
	i = 0;
	while (*s)
	{
		*str = f(i, *s);
		s++;
		str++;
		i++;
	}
	return (point);
}
