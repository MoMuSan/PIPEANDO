/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:11:24 by monmunoz          #+#    #+#             */
/*   Updated: 2024/11/10 20:43:24 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_kids(int argc, char *argv[], char *envp[])
{
	int		fd;
	int		i;
	char	**split;

	argc = 0;
	i = 0;
	fd = open(argv[0], O_RDONLY);
	if (fd < 0)
		perror("ErroR:");
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			split = ft_split(&envp[i][5], ':');
		i++;
	}
	ft_red(split, argv, envp);
}

//printf("ARGC= %d ARGV= %s\n", argc, argv[3]);
//printf(" --%d --- ARGV= %s\n", fd, argv[0]);