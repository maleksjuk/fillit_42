/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:02:14 by obanshee          #+#    #+#             */
/*   Updated: 2019/09/25 14:27:50 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **mas, int nbr_word)
{
	while (nbr_word)
	{
		free(mas[nbr_word]);
		nbr_word--;
	}
	free(mas);
	return (NULL);
}

static int	ft_nbr_word(const char *str, char c)
{
	int	nbr;

	nbr = 1;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c && *(str + 1) != c)
			nbr++;
		str++;
	}
	return (nbr);
}

static char	*ft_split(const char *str, char c, size_t *i)
{
	char	*word;
	size_t	len;

	if (!(word = (char *)malloc(sizeof(char) * (ft_strlen(str)))))
		return (NULL);
	len = 0;
	while (str[*i] != c && str[*i])
	{
		word[len] = str[*i];
		len++;
		(*i)++;
	}
	word[len] = '\0';
	while (str[*i] == c && str[*i])
		(*i)++;
	return (word);
}

char		**ft_strsplit(const char *str, char c)
{
	size_t	i;
	int		cur_word;
	int		nbr_word;
	char	**mas;

	if (!str)
		return (NULL);
	i = 0;
	cur_word = 0;
	nbr_word = ft_nbr_word(str, c);
	if (!(mas = (char **)malloc(sizeof(char *) * (nbr_word + 2))))
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (cur_word < nbr_word && str[i])
	{
		mas[cur_word] = ft_split(str, c, &i);
		if (mas[cur_word] == NULL)
			return (ft_free(mas, cur_word));
		cur_word++;
	}
	mas[cur_word] = NULL;
	return (mas);
}
