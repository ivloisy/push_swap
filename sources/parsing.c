/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 02:03:31 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/11 17:29:09 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static void	ft_putnbrl_fd(long n, int fd)
{
	long long	nb;

	nb = (long long)n;
	if (fd > -1)
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb = nb * -1;
		}
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbrl_fd(nb % 10, fd);
		}
		else
			ft_putchar_fd(nb + '0', fd);
	}
}
*/
static void	add_to_list(char ** av, t_ps *ps, int j)
{
	if (ft_atol(av[j]) > INT_MAX || ft_atol(av[j]) < INT_MIN)
		exit_error(EXIT_FAILURE);
	(void)ps;
}

static void	check_arg(int ac, char **av, t_ps *ps)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		if (av[j] && av[j][i] == '\0')
			exit_error(EXIT_FAILURE);
		if (av[j][i] == '-' || av[j][i] == '+')
			i++;
		while (ft_isdigit(av[j][i]))
			i++;
		if (av[j][i] != '\0')
			exit_error(EXIT_FAILURE);
		add_to_list(av, ps, j);
		j++;
	}
}

void	parsing(int ac, char **av, t_ps *ps)
{
	if (ac < 2)
		exit(EXIT_FAILURE);
	check_arg(ac, av, ps);
	(void)ps;
}
