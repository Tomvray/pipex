/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <tvray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:33:51 by tvray             #+#    #+#             */
/*   Updated: 2023/05/12 13:31:46 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		ft_print_shell(env);
		ft_putstr_fd("command not found: ", STDERR_FILENO);
		ft_putstr_fd(args[0], STDERR_FILENO);
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

void	ft_do_cmd(int fd_in, int fd_out, int i, t_data data)
{
	if (i == 0)
	{
		fd_in = open(data.av[1], O_RDONLY);
		if (fd_in == -1)
			ft_perror(data.av[1], data.env);
	}
	else if (i == data.ac - 4)
	{
		fd_out = open(data.av[i + 3], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd_out == -1)
			ft_perror(data.av[i + 3], data.env);
	}
	dup2(fd_in, 0);
	dup2(fd_out, 1);
	ft_execute_cmd(data.av[i + 2], data.env);
	close(fd_out);
	close(fd_in);
	exit(0);
}

void	ft_pipe(t_data data, int fd_in, int i)
{
	int			status;
	pid_t		pid;

	if (i < data.ac - 4)
	{
		if (pipe(data.fd_pipe) < 0)
			ft_exit("Error when pipe is called\n", 1);
	}
	pid = fork();
	if (pid < 0)
		ft_exit("Error when fork is called\n", 1);
	if (pid == 0)
	{
		if (i == data.ac - 4)
			ft_do_cmd(fd_in, -1, i, data);
		close(data.fd_pipe[0]);
		ft_do_cmd(fd_in, data.fd_pipe[1], i, data);
	}
	else if (i < data.ac - 4)
	{
		close(data.fd_pipe[1]);
		ft_pipe(data, data.fd_pipe[0], i + 1);
	}
	waitpid(pid, &status, 0);
	exit(WEXITSTATUS(status));
}

int	main(int ac, char **av, char **env)
{
	int		fd_pipe[2];
	pid_t	pid;
	int		status;
	t_data	data;

	if (ac < 5)
		ft_exit("Wrong number of arguments\n", 2);
	data.ac = ac;
	data.av = av;
	data.env = env;
	ft_pipe(data, 0, 0);
	return (0);
}
