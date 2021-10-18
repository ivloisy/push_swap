/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 02:03:31 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/19 00:27:42 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_to_list(t_ps *ps, char *s)
{
	int		*x;
	t_list	*lst;

	x = (int *)malloc(sizeof(int));
	if (x == NULL)
		exit_error(EXIT_FAILURE, ps);
	*x = ft_atoi(s);
	lst = ft_lstnew(x);
	ft_lstadd_back(&ps->a.lst, lst);
}

static void	check_arg(int ac, char **av, t_ps *ps)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	j = 0;
	while (++j < ac)
	{
		tab = ft_split(av[j], ' ');
		k = -1;
		while (tab[++k])
		{
			i = 0;
			if (tab[k] && tab[k][i] == '\0')
				exit_error(EXIT_FAILURE, ps);
			if (tab[k][i] == '-' || tab[k][i] == '+')
				i++;
			while (ft_isdigit(tab[k][i]))
				i++;
			if (tab[k][i] != '\0' || ft_atol(tab[k]) > INT_MAX
					|| ft_atol(tab[k]) < INT_MIN)
				exit_error(EXIT_FAILURE, ps);
			add_to_list(ps, tab[k]);
		}
	}
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
