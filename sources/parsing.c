/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 02:03:31 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/13 11:52:04 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_to_list(char **av, t_ps *ps, int j)
{
	int		*x;
	t_list	*lst;

	x = (int *)malloc(sizeof(int));
	if (x == NULL)
		exit_error(EXIT_FAILURE, ps);
	*x = ft_atoi(av[j]);
	lst = ft_lstnew(x);
	ft_lstadd_back(&ps->a.lst, lst);
/*	ft_putnbr_fd(*(int *)lst->content, 1);//
	ft_putchar_fd('\n', 1);//*/
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
			exit_error(EXIT_FAILURE, ps);
		if (av[j][i] == '-' || av[j][i] == '+')
			i++;
		while (ft_isdigit(av[j][i]))
			i++;
		if (av[j][i] != '\0' || ft_atol(av[j]) > INT_MAX
				|| ft_atol(av[j]) < INT_MIN)
			exit_error(EXIT_FAILURE, ps);
		add_to_list(av, ps, j);
		j++;
	}
	(void)ps;
}

void	check_dupli(t_ps *ps)
{
	t_list	*i;
	t_list	*j;

	i = ps->a.lst;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (*(int *)i->content == *(int *)j->content)
				exit_error(EXIT_FAILURE, ps);
			j = j->next;
		}
		i = i->next;
	}
}

static void	check_sort(t_ps *ps)
{
	t_list	*i;
	t_list	*j;

	i = ps->a.lst;
	j = i->next;
	while (j)
	{
		if (*(int *)i->content > *(int *)j->content)
			return ;
		i = i->next;
		j = j->next;
	}
	exit_error(EXIT_SUCCESS, ps);
}

void	parsing(int ac, char **av, t_ps *ps)
{
	if (ac < 2)
		exit_error(EXIT_FAILURE, ps);
	ps->l = ac - 1;
	check_arg(ac, av, ps);
	check_dupli(ps);
	check_sort(ps);
}
