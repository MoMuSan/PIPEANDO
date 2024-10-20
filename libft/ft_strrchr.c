/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:56:16 by monmunoz          #+#    #+#             */
/*   Updated: 2023/11/19 17:43:30 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (((char *)s) + i);
		i--;
	}
	return (NULL);
}
