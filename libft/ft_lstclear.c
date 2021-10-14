/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 22:24:07 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/14 20:50:37 by ivloisy          ###   ########.fr       */
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
