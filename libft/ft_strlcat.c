/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:57:24 by monmunoz          #+#    #+#             */
/*   Updated: 2023/11/19 17:41:34 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t		dest_len;
	size_t		total_len;
	const char	*s;

	if ((!dest || !src) && ! dstsize)
		return (0);
	s = src;
	dest_len = 0;
	while (*(dest + dest_len) && dest_len < dstsize)
		dest_len++;
	if (dest_len < dstsize)
		total_len = dest_len + ft_strlen(s);
	else
		return (dstsize + ft_strlen(s));
	while (*s && (dest_len + 1) < dstsize)
	{
		*(dest + dest_len) = *s;
		s++;
		dest_len++;
	}
	*(dest + dest_len) = '\0';
	return (total_len);
}
