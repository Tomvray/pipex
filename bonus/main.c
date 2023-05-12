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

void	ft_do_cmd1(int fd_out, char **av, char **env)
{
	int		fd1;

	fd1 = open(av[1], O_RDONLY);
	if (fd1 == -1)
		ft_perror(av[1], env);
	dup2(fd1, 0);
	dup2(fd_out, 1);
	ft_execute_cmd(av[2], env);
	close(fd_out);
	close(fd1);
	exit(0);
}

void	ft_do_cmd2(int fd_in, int i, char **av, char **env)
{
	int		fd2;

	fd2 = open(av[i + 3], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd2 == -1)
		ft_perror(av[i + 3], env);
	dup2(fd2, 1);
	dup2(fd_in, 0);
	ft_execute_cmd(av[i + 2], env);
	close(fd_in);
	close(fd2);
	exit(0);
}

void	ft_do_cmd(int fd_in, int fd_out, int i, char **av, char **env)
{
	dup2(fd_in, 0);
	dup2(fd_out, 1);
	ft_execute_cmd(av[i + 2], env);
	close(fd_out);
	close(fd_in);
	exit(0);
}

void	ft_pipe(t_data data, int fd_in)
{
	int		fd_pipe_out[2];
	static int	i = 0;
	int		status;
	pid_t	pid;

	if (i < data.ac - 4)
	{
		if (pipe(fd_pipe_out) < 0)
			ft_exit("Error when pipe is called\n", 1);
	}
	pid = fork();
	if (pid < 0)
		ft_exit("Error when fork is called\n", 1);
	if (pid == 0)
	{
		if (i == data.ac - 4)
			ft_do_cmd2(fd_in, i, data.av, data.env);
		close(fd_pipe_out[0]);
		if (i == 0)
			ft_do_cmd1(fd_pipe_out[1], data.av, data.env);
		else
			ft_do_cmd(fd_in, fd_pipe_out[1], i, data.av, data.env);
	}
	else if (i < data.ac - 4)
	{
		close(fd_pipe_out[1]);
		i += 1;
		ft_pipe(data, fd_pipe_out[0]);
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
	ft_pipe(data, 0);
	return (0);
}
