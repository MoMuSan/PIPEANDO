/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:11:24 by monmunoz          #+#    #+#             */
/*   Updated: 2024/11/24 20:12:20 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
//read end
void	ft_tube_read(int tub[2], int fd)
{
	dup2(fd, 0);
	close(tub[0]);
	dup2(tub[1], 1);
	close(tub[1]);
	close(fd);
}

//write end
void	ft_tube_write(int tub[2], int fd)
{
	dup2(fd, 1);
	close(tub[1]);
	dup2(tub[0], 0);
	close(tub[0]);
	close(fd);
}

void	ft_kid_one(int tub[2], char *argv[], char *envp[], char *path[])
{
	int		fd;
	char	**cmd1;

	fd = open(argv[0], O_RDONLY);
	if (fd < 0)
	{
		perror("ErroR:");
		exit (1);
	}
	ft_tube_read(tub, fd);
	cmd1 = ft_split(argv[1], ' ');
	ft_red_in(path, cmd1, envp);
}

void	ft_kid_two(int tub[2], char *argv[], char *envp[], char *path[])
{
	int		fd;
	char	**cmd2;

	fd = open(argv[1], O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (fd < 0)
		perror("Error:");
	ft_tube_write(tub, fd);
	cmd2 = ft_split(argv[0], ' ');
	ft_red_in(path, cmd2, envp);
}
