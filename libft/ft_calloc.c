/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 05:36:45 by ivloisy           #+#    #+#             */
/*   Updated: 2019/11/06 01:35:52 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	tab = NULL;
	tab = malloc(count * size);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
}
