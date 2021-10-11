/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 02:03:31 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/11 04:40:59 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	while (j < ac)
	{
		i = 0;
		if (av[j] && av[j][i] == '\0')
			exit_error(EXIT_FAILURE);
		ft_putstr_fd("hey\n", 1);///
		if (av[j][i] == '-' || av[j][i] == '+')
			i++;
		ft_putstr_fd("hep\n", 1);///
		while (av[j][i] && ft_isdigit(av[j][i]))
		{
			ft_putchar_fd(av[j][i], 1);
			ft_putchar_fd(av[j][i], 1);
			i++;
		}
		if (av[j][i] != '\0')
			exit_error(EXIT_FAILURE);
		j++;
	}
}

void	parsing(int ac, char **av, t_ps *ps)
{
	if (ac < 2)
		exit(EXIT_FAILURE);
	else
	{
		ft_putstr_fd("hey\n", 1);///
		check_arg(ac, av);
	}
	(void)ps;
}
