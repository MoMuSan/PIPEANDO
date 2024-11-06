/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:45:43 by monmunoz          #+#    #+#             */
/*   Updated: 2024/11/06 22:53:46 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_red(char *split, char *argv, char *envp)
{
	char	*join;
	int		i;
	int		acc;

	i = 0;

	while (split && split[i] != '\0')
	{
		join = ft_strjoin(&split[i], "/");
		join = ft_strjoin(join, &argv[1]);
		acc = access(join, 0111);
		if (acc == 0)
			break ;
		i++;
	}
	printf("AAA\n");
	execve(join, argv[1], &envp);
}

