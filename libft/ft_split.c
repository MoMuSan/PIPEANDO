/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:24:13 by monmunoz          #+#    #+#             */
/*   Updated: 2024/05/02 20:22:40 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	n_words(const char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (word);
}

static char	**free_me(const char *s, char c, char **ptr, int row)
{
	int	i;
	int	len;
	int	start;

	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i++] != c && (s[i] == '\0' || s[i] == c))
		{
			len = i - start;
			ptr[row] = ft_substr(s, start, len);
			if (!ptr[row])
			{
				while (row >= 0)
					free (ptr[row--]);
				free (ptr);
				return (NULL);
			}
			row++;
		}
	}
	ptr[row] = NULL;
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	int		row;

	row = 0;
	ptr = (char **)malloc(((n_words(s, c)) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr = free_me(s, c, ptr, row);
	return (ptr);
}
