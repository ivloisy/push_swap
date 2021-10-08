/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:33:39 by ivloisy           #+#    #+#             */
/*   Updated: 2019/10/25 08:25:47 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize && src[i] != 0)
		{
			dst[i] = src[i];
			i++;
		}
		if (i < dstsize)
			dst[i] = '\0';
		else
			dst[i - 1] = '\0';
	}
	return (ft_strlen(src));
}
