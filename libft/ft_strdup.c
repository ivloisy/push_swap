/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 03:08:34 by ivloisy           #+#    #+#             */
/*   Updated: 2019/11/13 03:26:47 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	l;
	char	*s2;

	i = 0;
	l = 0;
	while (s1[l])
		l++;
	s2 = (char *)malloc(sizeof(char) * (l + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < l)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
