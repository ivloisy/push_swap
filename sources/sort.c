/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:21:46 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/20 15:22:17 by ivloisy          ###   ########.fr       */
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

static void	rotate_push(t_ps *ps, int j)
{
	int	i;

	i = 0;
	if (j < ft_lstsize(ps->a.lst) / 2)
	{
		while (i < j)
		{
			rotate(ps, 'a');
			i++;
		}
	}
	else
	{
		while (i < ft_lstsize(ps->a.lst) - j)
		{
			reverse_rotate(ps, 'a');
			i++;
		}
	}
	push(ps, 'b');
}

static void	push_smaller(t_ps *ps)
{
	t_list	*lst;
	int		i;
	int		j;
	int		smaller;
	
	lst = ps->a.lst;
	i = 0;
	j = 0;
	smaller = *(int *)lst->content;
	while (lst->next)
	{
		i++;
		if (smaller > *(int *)lst->next->content)
		{
			smaller = *(int *)lst->next->content;
			j = i;
		}
		lst = lst->next;
	}
	rotate_push(ps, j);
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
	else if (l == 4 || l == 5)
	{
		if (l == 5)
			push_smaller(ps);
		push_smaller(ps);
		sort_three(ps);
		if (l == 5)
			push(ps, 'a');
		push(ps, 'a');
	}
/*	else if (l > 5)
		sort_big(ps); */
}
