/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:16:43 by monmunoz          #+#    #+#             */
/*   Updated: 2023/11/25 00:25:21 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if ((num * size) == 0)
		ptr = malloc(0);
	else
		ptr = malloc(num * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero((void *)ptr, num * size);
	return (ptr);
}
