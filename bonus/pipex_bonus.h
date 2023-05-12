#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <sys/wait.h>
# include <errno.h>
#include <stdio.h>

typedef struct s_data
{
	char	**env;
	char	**av;
	int		ac;
}	t_data;

void	*ft_free_tab(char	**ptr);
void	ft_exit(char *str, int exit_code);
char	*ft_path(char	*cmd, char **env);
void	ft_print_shell(char **env);
void    ft_perror(char *file_name, char **env);

#endif