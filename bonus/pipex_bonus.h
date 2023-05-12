/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <tvray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:33:55 by tvray             #+#    #+#             */
/*   Updated: 2023/05/12 13:06:16 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <sys/wait.h>
# include <errno.h>

typedef struct s_data
{
	char	**env;
	char	**av;
	int		ac;
	int		fd_pipe[2];
}	t_data;

void	*ft_free_tab(char	**ptr);
void	ft_exit(char *str, int exit_code);
char	*ft_path(char	*cmd, char **env);
void	ft_print_shell(char **env);
void	ft_perror(char *file_name, char **env);

#endif