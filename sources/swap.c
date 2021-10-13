/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:37:32 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/13 13:07:28 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_a(t_ps *ps, int p)
{
	t_list	*tmp;
	void	*vtmp;

	if (ps->a.lst->next != NULL)
	{
		tmp = ps->a.lst->next;
		vtmp = tmp->content;
		tmp->content = ps->a.lst->content;
		ps->a.lst->content = vtmp;
		if (p == 1)
		{
			ft_putstr_fd("sa", 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

static void	swap_b(t_ps *ps, int p)
{
	t_list	*tmp;
	void	*vtmp;

	if (ps->b.lst->next != NULL)
	{
		tmp = ps->b.lst->next;
		vtmp = tmp->content;
		tmp->content = ps->b.lst->content;
		ps->b.lst->content = vtmp;
		if (p == 1)
		{
			ft_putstr_fd("sb", 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	swap(t_ps *ps, int stack, int p)
{
	if (stack == 'a')
		swap_a(ps, p);
	if (stack == 'b')
		swap_b(ps, p);
	if (stack == 's')
	{
		swap_a(ps, p);
		swap_b(ps, p);
	}
}
