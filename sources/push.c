/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:20:49 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/18 19:06:30 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a(t_ps *ps)
{
	t_list	*tmp;

	if (ps->b.lst->content)
	{
		tmp = ps->b.lst;
		ps->b.lst = ps->b.lst->next;
		tmp->next = ps->a.lst;
		ps->a.lst = tmp;
		ft_putstr_fd("pa", 1);
		ft_putchar_fd('\n', 1);
	}
}

static void	push_b(t_ps *ps)
{
	t_list	*tmp;

	if (ps->a.lst->content)
	{
		tmp = ps->a.lst;
		ps->a.lst = ps->a.lst->next;
		tmp->next = ps->b.lst;
		ps->b.lst = tmp;
		ft_putstr_fd("pb", 1);
		ft_putchar_fd('\n', 1);
	}
}

void	push(t_ps *ps, int stack)
{
	if (stack == 'a')
		push_a(ps);
	if (stack == 'b')
		push_b(ps);
}
