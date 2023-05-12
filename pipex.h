/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <tvray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:05:31 by tvray             #+#    #+#             */
/*   Updated: 2023/05/12 14:05:52 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <sys/wait.h>
# include <errno.h>

void	*ft_free_tab(char	**ptr);
char	**ft_pipex_split(char const *str);
void	ft_exit(char *str, int exit_code);
char	*ft_path(char	*cmd, char **env);
void	ft_print_shell(char **env);
void	ft_perror(char *file_name, char **env);

#endif