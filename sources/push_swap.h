/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:25:04 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/13 12:33:03 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	char	id;
	t_list	*lst;
}t_stack;

typedef struct s_ps
{
	int		l;
	t_stack	a;
	t_stack	b;
}t_ps;

void	parsing(int ac, char **av, t_ps *ps);
void	exit_error(int x, t_ps *ps);
void	swap(t_ps *ps, int stack, int p);

void	display(t_ps *ps);//

#endif
