/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:24:22 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/13 14:50:11 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps	ps;

	parsing(ac, av, &ps);
	swap(&ps, 'a', 1);//
	push(&ps, 'b', 1);
	display(&ps);
	system("leaks push_swap"); //
	return (EXIT_SUCCESS);
}
