/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <tvray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:56:36 by tvray             #+#    #+#             */
/*   Updated: 2023/05/08 16:08:01 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute_cmd(char *str, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(str, ' ');
	if (!args)
		ft_exit("Error allocating memory\n", 1);
	path = ft_path(args[0], env);
	if (!path)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_free_tab(args);
		ft_exit("\n", 127);
	}
	if (execve(path, args, env) == -1)
	{
		free(path);
		ft_free_tab(args);
		ft_exit("cant execute cmd\n", 1);
	}
	free(path);
	ft_free_tab(args);
}

void	ft_do_cmd1(int fd_pipe[2], char **av, char **env)
{
	int		fd1;

	fd1 = open(av[1], O_RDONLY);
	if (fd1 == -1)
		ft_perror(av[1], env);
	dup2(fd1, 0);
	dup2(fd_pipe[1], 1);
	close(fd_pipe[0]);
	ft_execute_cmd(av[2], env);
	close(fd_pipe[1]);
	close(fd1);
	exit(0);
}

void	ft_do_cmd2(int fd_pipe[], char **av, char **env)
{
	int		fd2;

	fd2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd2 == -1)
	{
		ft_perror(av[4], env);
	}
	dup2(fd2, 1);
	dup2(fd_pipe[0], 0);
	close(fd_pipe[1]);
	ft_execute_cmd(av[3], env);
	close(fd_pipe[0]);
	close(fd2);
}

int	main(int ac, char **av, char **env)
{
	int		fd_pipe[2];
	pid_t	pid;
	int		status;

	if (ac != 5)
		ft_exit("Wrong number of arguments\n", 1);
	if (pipe(fd_pipe) == -1)
		ft_exit("pipe issue\n", 1);
	pid = fork();
	if (pid == -1)
		ft_exit("fork issue\n", 1);
	else if (pid == 0)
		ft_do_cmd1(fd_pipe, av, env);
	if (pid > 0)
		ft_do_cmd2(fd_pipe, av, env);
	waitpid(pid, &status, 0);
	return (0);
}
