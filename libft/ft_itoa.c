/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:05:04 by monmunoz          #+#    #+#             */
/*   Updated: 2023/11/19 17:33:58 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num(int nb)
{
	int			i;
	long int	n;

	n = nb;
	i = 1;
	if (n < 0)
	{
		n = (n * (-1));
		i = 2;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			nb;
	long int	c;

	nb = num(n);
	c = n;
	str = (char *)malloc((nb + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = 48;
	str[nb] = 0;
	if (c < 0)
	{
		str[0] = '-';
		c = c * (-1);
	}
	while (c > 0 && (nb - 1) >= 0)
	{
		str[nb - 1] = (c % 10) + 48;
		c = c / 10;
		nb--;
	}
	return (str);
}
