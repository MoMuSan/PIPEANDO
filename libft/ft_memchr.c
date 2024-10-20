/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:20:21 by monmunoz          #+#    #+#             */
/*   Updated: 2023/11/19 17:35:44 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p;
	unsigned char		t;

	i = 0;
	p = s;
	t = c;
	while (i < n)
	{
		if (p[i] == t)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}
