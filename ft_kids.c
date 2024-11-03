/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:11:24 by monmunoz          #+#    #+#             */
/*   Updated: 2024/11/03 20:57:44 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_kids(int argc, char *argv[], char *envp[])
{
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		perror("Error:");
	printf("ARGC= %d ARGV= %s\n", argc, *argv);
	while (envp[i] != NULL)
	{
		i++;
	}

}

