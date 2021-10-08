/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 02:25:35 by ivloisy           #+#    #+#             */
/*   Updated: 2021/09/11 18:08:44 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;
	t_list	*new;

	res = NULL;
	if (lst && f)
	{
		tmp = lst;
		res = ft_lstnew(f(tmp->content));
		if (res == NULL)
			return (NULL);
		tmp = tmp->next;
		while (tmp)
		{
			new = ft_lstnew(f(tmp->content));
			if (new == NULL)
			{
				ft_lstclear(&res, del);
				return (NULL);
			}
			ft_lstadd_back(&res, new);
			tmp = tmp->next;
		}
	}
	return (res);
}
