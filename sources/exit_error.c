/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 04:09:11 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/13 12:05:34 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(int x, t_ps *ps)
{
	ft_bzero(ps, sizeof(ps));
	ft_putstr_fd("Error\n", 2);
	system("leaks push_swap"); //
	exit(x);
}
