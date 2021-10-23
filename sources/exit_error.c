/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 04:09:11 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/23 01:15:45 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	protect_malloc(void *x)
{
	if (x == NULL)
		exit_error(EXIT_FAILURE);
}

void	ft_free(void *x)
{
	free(x);
	x = NULL;
}

void	exit_error(int x)
{
	if (x == EXIT_FAILURE)
		ft_putstr_fd("Error\n", 2);
	exit(x);
}
