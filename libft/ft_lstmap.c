/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:46:04 by monmunoz          #+#    #+#             */
/*   Updated: 2023/12/12 22:48:23 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*n_node;
	void	*n_content;

	new = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		n_content = (*f)(lst->content);
		n_node = ft_lstnew(n_content);
		if (!n_node)
		{
			(*del)(n_content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, n_node);
		lst = lst->next;
	}
	return (new);
}
