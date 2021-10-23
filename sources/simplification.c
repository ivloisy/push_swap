/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplification.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:20:58 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/23 01:22:28 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	order(t_ps *ps, int *tab)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	t = 0;
	while (i < ft_lstsize(ps->a.lst))
	{
		j = i;
		while (j < ft_lstsize(ps->a.lst))
		{
			if (tab[i] > tab[j])
			{
				t = tab[j];
				tab[j] = tab[i];
				tab[i] = t;
			}
			j++;
		}
		i++;
	}
}

static void	replace_lst(t_ps *ps, int *tmp)
{
	t_list	*lst;
	int		i;

	lst = ps->a.lst;
	i = 0;
	while (i < ft_lstsize(ps->a.lst))
	{
		*(int *)lst->content = tmp[i];
		lst = lst->next;
		i++;
	}
}

static int	replace(t_ps *ps, int *tab)
{
	t_list	*lst;
	int		i;
	int		j;
	int		*tmp;

	i = -1;
	tmp = (int *)malloc(sizeof(int) * ft_lstsize(ps->a.lst));
	if (tmp == NULL)
		return (0);
	while (++i < ft_lstsize(ps->a.lst))
	{
		lst = ps->a.lst;
		j = -1;
		while (++j < ft_lstsize(ps->a.lst))
		{
			if (*(int *)lst->content == tab[i])
				tmp[j] = i;
			lst = lst->next;
		}
	}
	replace_lst(ps, tmp);
	free (tmp);
	return (1);
}

static int	create_tab(t_ps *ps, int *tab)
{
	t_list	*lst;
	int		i;

	lst = ps->a.lst;
	i = 0;
	while (lst)
	{
		tab[i] = *(int *)lst->content;
		lst = lst->next;
		i++;
	}
	order(ps, tab);
	if (replace(ps, tab) == 0)
		return (0);
	return (1);
}

void	simplification(t_ps *ps)
{
	int	*tab;

	tab = (int *)malloc(sizeof(int) * ft_lstsize(ps->a.lst));
	if (tab == NULL)
		exit_error(EXIT_FAILURE);
	if (create_tab(ps, tab) == 0)
	{
		free (tab);
		tab = NULL;
		exit_error(EXIT_FAILURE);
	}
	free(tab);
	tab = NULL;
}
