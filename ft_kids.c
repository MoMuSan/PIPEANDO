/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:11:24 by monmunoz          #+#    #+#             */
/*   Updated: 2024/11/03 22:25:59 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_kids(int argc, char *argv[], char *envp[])
{
	int		fd;
	int		i;
	char	**split;
	char	*join;

	i = 0;
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		perror("Error:");
	printf("ARGC= %d ARGV= %s\n", argc, *argv);
	while (envp[i] != NULL)
	{
		if (ft_strcmp(envp[i], "PATH=", 5) == 0)
			split = ft_split(&envp[i][5], ':');
		i++;
	}
	i  = 0;
	while (split && split[i] != NULL)
	{
		
	}
}

