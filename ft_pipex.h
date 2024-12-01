/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:47:40 by monmunoz          #+#    #+#             */
/*   Updated: 2024/12/01 15:38:05 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>

int		ft_init(char *argv[], char *envp[], char *path[]);
int		ft_second_son(int tub[], char *argv[], char *envp[], char *path[]);
void	ft_kid_one(int tub[2], char *argv[], char *envp[], char *path[]);
void	ft_kid_two(int tub[2], char *argv[], char *envp[], char *path[]);
void	ft_tube_read(int tub[2], int fd);
void	ft_tube_write(int tub[2], int fd);
void	ft_red_in(char **path, char **cmd1, char **envp);
void	ft_free_path(char **path);

#endif