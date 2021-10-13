/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:20:49 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/13 15:58:27 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a(t_ps *ps, int p)
{
	t_list	*lst;

	if (ps->b.lst->content)
	{
		lst = ps->b.lst;
		ps->b.lst = ps->b.lst->next;
		lst->next = ps->a.lst;
		ps->a.lst = lst;
		if (p == 1)
		{
			ft_putstr_fd("pa", 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

static void	push_b(t_ps *ps, int p)
{
	t_list	*lst;

	if (ps->a.lst->content)
	{
		lst = ps->a.lst;
		ps->a.lst = ps->a.lst->next;
		lst->next = ps->b.lst;
		ps->b.lst = lst;
		if (p == 1)
		{
			ft_putstr_fd("pb", 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	push(t_ps *ps, int stack, int p)
{
	if (stack == 'a')
		push_a(ps, p);
	if (stack == 'b')
		push_b(ps, p);
}
