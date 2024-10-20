/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:56:41 by monmunoz          #+#    #+#             */
/*   Updated: 2023/12/10 19:23:59 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	size;
	t_list			*start;

	size = 0;
	start = lst;
	while (start != NULL)
	{
		start = start->next;
		size++;
	}
	return (size);
}
