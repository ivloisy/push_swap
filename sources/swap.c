/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:37:32 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/18 19:07:59 by ivloisy          ###   ########.fr       */
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

void	swap(t_ps *ps, int stack)
{
	if (stack == 'a')
		swap_a(ps, 1);
	if (stack == 'b')
		swap_b(ps, 1);
	if (stack == 's')
	{
		swap_a(ps, 0);
		swap_b(ps, 0);
		ft_putstr_fd("ss", 1);
		ft_putchar_fd('\n', 1);
	}
}
