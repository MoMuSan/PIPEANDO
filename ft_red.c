/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:45:43 by monmunoz          #+#    #+#             */
/*   Updated: 2024/12/01 15:39:15 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_red_in(char **path, char **cmd1, char **envp)
{
	char	*join;
	int		i;

	envp = NULL;
	i = 0;
	if (ft_strrchr(cmd1[0], '/') != 0)
		join = cmd1[0];
	else
	{
		while (path && path[i] != NULL)
		{
			join = ft_strjoin(path[i], "/");
			join = ft_strjoin(join, cmd1[0]);
			if (access(join, F_OK) == 0)
				break ;
			i++;
		}
	}
	ft_free_path(path);
	execve(join, cmd1, envp);
	perror(cmd1[0]);
	exit (errno);
}

void	ft_free_path(char **path)
{
	int	j;

	j = 0;
	while (path[j] != 0)
	{
		free(path[j]);
		j++;
	}
	free(path);
}
