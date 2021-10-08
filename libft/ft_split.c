/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:04:24 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/08 18:04:28 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strcdup(char const *src, char c)
{
	char	*dest;
	size_t	i;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	dest = (char*)malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t	ft_count_words(char const *str, char c)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
			i++;
		if (str[i - 1] != c)
			x++;
	}
	return (x);
}

static	size_t	ft_new_word(char const *str, size_t i, char c)
{
	if (!(str[i] == c) && (i == 0 || (str[i - 1] == c)))
		return (1);
	else
		return (0);
}

static void		ft_clean(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (ft_new_word(s, i, c) == 1)
		{
			if (!(tab[j] = ft_strcdup(s + i, c)))
			{
				ft_clean(tab, j);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}