/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <tvray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:13:15 by tvray             #+#    #+#             */
/*   Updated: 2023/05/08 15:20:49 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *file_name)
{
	if (errno == 13)
		ft_putstr_fd("permission denied: ", 2);
	else if (errno == 2)
		ft_putstr_fd("no such file or directory: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putchar_fd('\n', 2);
	if (errno == 13)
		exit(1);
	exit(errno);
}

int	ft_error(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(1);
}

void	ft_exit(char *str, int exit_code)
{
	ft_putstr_fd(str, 2);
	exit(exit_code);
}
