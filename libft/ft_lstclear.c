/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:50:30 by monmunoz          #+#    #+#             */
/*   Updated: 2023/12/10 21:06:52 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*ptr;

	if (!lst)
		return ;
	while (*lst)
	{
		ptr = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(ptr);
	}
}
