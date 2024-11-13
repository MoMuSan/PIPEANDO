/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:44:48 by monmunoz          #+#    #+#             */
/*   Updated: 2024/11/13 22:27:48 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_init(int argc, char *argv[], char *envp[])
{
	int		tub[2];
	pid_t	pid;

	if (pipe(tub) == -1)
	{
		perror("Pipe error");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		return (1);
	}
	if (pid == 0)
		ft_kids(argc, &argv[1], envp);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
	{
		ft_putstr_fd("Wrong number of arguments\n", 1);
		return (1);
	}
	ft_init(argc, argv, envp);
	return (0);
}
