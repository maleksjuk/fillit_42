/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:25:17 by obanshee          #+#    #+#             */
/*   Updated: 2019/09/25 13:02:12 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	i = 0;
	if (!len || dst == src)
		return (dst);
	if (dst > src)
		while (len)
		{
			len--;
			*(unsigned char*)(dst + len) = *(unsigned char*)(src + len);
		}
	else
		while (i < len)
		{
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
			i++;
		}
	return (dst);
}
