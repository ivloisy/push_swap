/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:21:46 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/18 22:14:12 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)ps->a.lst->content;
	b = *(int *)ps->a.lst->next->content;
	c = *(int *)ps->a.lst->next->next->content;
	if (b > c && c > a)
	{
		swap(ps, 'a');
		rotate(ps, 'a');
	}
	if (c > a && a > b)
		swap(ps, 'a');
	if (b > a && a > c)
		reverse_rotate(ps, 'a');
	if (a > c && c > b)
		rotate(ps, 'a');
	if (a > b && b > c)
	{
		swap(ps, 'a');
		reverse_rotate(ps, 'a');
	}
}

void	sort(t_ps *ps)
{
	int	l;

	l = ft_lstsize(ps->a.lst);
	if (l == 1)
		return ;
	else if (l == 2)
		swap(ps, 'a');
	else if (l == 3)
		sort_three(ps);
/*	else if (l <= 5)
		sort_small(ps);
	else if (l > 5)
		sort_big(ps); */
}
