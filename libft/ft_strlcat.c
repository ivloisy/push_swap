/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 05:02:40 by ivloisy           #+#    #+#             */
/*   Updated: 2019/10/31 05:19:26 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	rsl;

	i = ft_strlen(dst);
	j = 0;
	if (dstsize <= 0)
		return (ft_strlen(src));
	if (dstsize < ft_strlen(dst))
		rsl = ft_strlen(src) + dstsize;
	else
	{
		rsl = ft_strlen(src) + ft_strlen(dst);
		while (src[j] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
	}
	return (rsl);
}
