/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:43:00 by monmunoz          #+#    #+#             */
/*   Updated: 2023/11/19 17:43:47 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*cut;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
		i++;
	while (size > 0 && ft_strrchr(set, s1[size - 1]))
		size--;
	cut = ft_substr(s1, i, (size - i));
	return (cut);
}
