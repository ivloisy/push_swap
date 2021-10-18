/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:24:22 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/19 00:28:28 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps	ps;

/* 	int i = 1;
	while (i < ac)
	{
		ft_putstr_fd(av[i], 1);
		i++;
	} */
	parsing(ac, av, &ps);
/* 	swap(&ps, 'a');//
	push(&ps, 'b');
	rotate(&ps, 'a');
	rotate(&ps, 'b');
	push(&ps, 'b');
	swap(&ps, 's');
	rotate(&ps, 'b');
	reverse_rotate(&ps, 'a');
	reverse_rotate(&ps, 'b');
	reverse_rotate(&ps, 'r'); */
//	reverse_rotate(&ps, 'r');
	sort(&ps);
//	display(&ps);
//	system("leaks push_swap"); //
	return (EXIT_SUCCESS);
}
