/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:07:34 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/18 19:04:16 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_b(t_ps *ps, int p)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*first;
	int		i;

	i = ft_lstsize(ps->b.lst);
	if (ft_lstsize(ps->b.lst) > 1)
	{
		first = ft_lstlast(ps->b.lst);
		tmp = ps->b.lst;
		tmp2 = ps->b.lst;
		while (i - 2 > 0)
		{
			tmp2 = tmp2->next;
			i--;
		}
		tmp2->next = NULL;
		first->next = tmp;
		ps->b.lst = first;
		if (p == 1)
		{
			ft_putstr_fd("rrb", 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

static void	reverse_rotate_a(t_ps *ps, int p)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*first;
	int		i;

	i = ft_lstsize(ps->a.lst);
	if (ft_lstsize(ps->a.lst) > 1)
	{
		first = ft_lstlast(ps->a.lst);
		tmp = ps->a.lst;
		tmp2 = ps->a.lst;
		while (i - 2 > 0)
		{
			tmp2 = tmp2->next;
			i--;
		}
		tmp2->next = NULL;
		first->next = tmp;
		ps->a.lst = first;
		if (p == 1)
		{
			ft_putstr_fd("rra", 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	reverse_rotate(t_ps *ps, int stack)
{
	if (stack == 'a')
		reverse_rotate_a(ps, 1);
	if (stack == 'b')
		reverse_rotate_b(ps, 1);
	if (stack == 'r')
	{
		reverse_rotate_a(ps, 0);
		reverse_rotate_b(ps, 0);
		ft_putstr_fd("rrr", 1);
		ft_putchar_fd('\n', 1);
	}
}
