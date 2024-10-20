/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:25:06 by monmunoz          #+#    #+#             */
/*   Updated: 2023/11/19 17:44:03 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > ((size_t)ft_strlen(s) - (size_t)start))
		len = ((size_t)ft_strlen(s) - (size_t)start);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (s[start] != '\0' && j < len)
	{
		sub[i] = s[start];
		start++;
		i++;
		j++;
	}
	sub[i] = '\0';
	return ((char *)sub);
}
