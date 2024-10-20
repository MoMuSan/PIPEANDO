/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:47:53 by monmunoz          #+#    #+#             */
/*   Updated: 2023/11/19 17:40:57 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen((char *)s);
	while (i <= j)
	{
		if (s[i] == (char)c)
			return (((char *)s) + i);
		i++;
	}
	return (NULL);
}
