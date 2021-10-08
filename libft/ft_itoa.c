/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 06:12:27 by ivloisy           #+#    #+#             */
/*   Updated: 2021/09/11 17:11:43 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int		l;
	long	nb;

	l = 0;
	nb = n;
	if (n < 0)
	{
		l++;
		nb = n * -1;
	}
	while (nb / 10)
	{
		l++;
		nb = nb / 10;
	}
	l++;
	return (l);
}

static char	*ft_str(long n, int l, char *s)
{
	long	nb;
	int		neg;

	nb = n;
	neg = 0;
	if (nb < 0)
	{
		neg = 1;
		nb = nb * -1;
	}
	while (l > 0)
	{
		s[l] = (nb % 10) + '0';
		nb = nb / 10;
		l--;
	}
	if (neg)
		s[l] = '-';
	else
		s[l] = (nb % 10) + '0';
	return (s);
}

char	*ft_itoa(int n)
{
	int		l;
	char	*res;

	l = ft_len(n);
	res = (char *)malloc(sizeof(char) * (l + 1));
	if (res == NULL)
		return (NULL);
	res = ft_str(n, l - 1, res);
	res[l] = '\0';
	return (res);
}
