/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 22:24:07 by ivloisy           #+#    #+#             */
/*   Updated: 2019/11/08 02:11:41 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst && *lst && del)
	{
		tmp = *lst;
		while (tmp)
		{
			del(tmp->content);
			free(tmp);
			tmp = tmp->next;
		}
		*lst = NULL;
	}
}
