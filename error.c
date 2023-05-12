/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <tvray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:13:15 by tvray             #+#    #+#             */
/*   Updated: 2023/05/12 14:00:12 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_print_shell(char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env && env[i] && ft_strncmp(env[i], "SHELL=", 6))
		i++;
	if (!env || !env[i])
		return ;
	j = ft_strlen(env[i]);
	while (j > 5 && env[i][j] != '/')
		j --;
	ft_putstr_fd(env[i] + j + 1, 2);
	ft_putstr_fd(": ", 2);
}

void	ft_perror(char *file_name, char **env)
{
	ft_print_shell(env);
	if (errno == 13)
		ft_putstr_fd("permission denied: ", 2);
	else if (errno == 2)
		ft_putstr_fd("no such file or directory: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

void	ft_exit(char *str, int exit_code)
{
	ft_putstr_fd(str, 2);
	exit(exit_code);
}
