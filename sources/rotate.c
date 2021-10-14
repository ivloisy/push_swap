/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:17:03 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/14 15:36:37 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_ps *ps, int p)
{
	t_list	*tmp;
	t_list	*last;

	if (ps->a.lst->next != NULL)
	{
		tmp = ps->a.lst;
		last = ps->a.lst;
		ps->a.lst = ps->a.lst->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = last;
		last->next = NULL;
		if (p == 1)
		{
			ft_putstr_fd("ra", 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

static void	rotate_b(t_ps *ps, int p)
{
	t_list	*tmp;
	t_list	*last;

	if (ps->b.lst->next != NULL)
	{
		tmp = ps->b.lst;
		last = ps->b.lst;
		ps->b.lst = ps->b.lst->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = last;
		last->next = NULL;
		if (p == 1)
		{
			ft_putstr_fd("rb", 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	rotate(t_ps *ps, int stack, int p)
{
	if (stack == 'a')
		rotate_a(ps, p);
	if (stack == 'b')
		rotate_b(ps, p);
	if (stack == 'r')
	{
		rotate_a(ps, p);
		rotate_b(ps, p);
	}
}
