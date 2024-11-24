/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:44:48 by monmunoz          #+#    #+#             */
/*   Updated: 2024/11/24 20:10:30 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_second_son(int tub[], char *argv[], char *envp[], char *path[])
{
	pid_t	second_son;
	int		status;

	second_son = fork();
	if (second_son < 0)
	{
		perror("Fork failed");
		return (1);
	}
	if (second_son == 0)
		ft_kid_two(tub, argv, envp, path);
	else
	{
		close(tub[0]);
		close(tub[1]);
		waitpid(second_son, &status, WNOHANG);
	}
	return (0);
}

int	ft_init(char *argv[], char *envp[], char *path[])
{
	int		tub[2];
	pid_t	first_son;

	if (pipe(tub) == -1)
	{
		perror("Pipe error");
		return (1);
	}
	first_son = fork();
	if (first_son < 0)
	{
		perror("Fork failed");
		return (1);
	}
	if (first_son == 0)
		ft_kid_one(tub, &argv[1], envp, path);
	else
		ft_second_son(tub, &argv[3], envp, path);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**path;
	int		i;

	i = 0;
	if (argc != 5)
	{
		ft_putstr_fd("Wrong number of arguments\n", 1);
		return (1);
	}
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = ft_split(&envp[i][5], ':');
		i++;
	}
	ft_init(argv, envp, path);
	return (0);
}
