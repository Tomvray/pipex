#include "pipex.h"

int	ft_error()
{
	write(2, "Error\n", 6);
	return (1);
}

void	*ft_free_tab(char	**ptr)
{
	int	i;

	if (ptr)
	{
		i = 0;
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
	}
	return (NULL);
}

void	ft_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

char	*ft_path(char	*str, char **env)
{
	char	*all_paths;
	char	*path;
	int		i;

	i = 0;
	while(ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		ft_exit("path not in env\n");
	all_paths = env[i] + 5;
	while (*all_paths)
	{
		i = 0;
		while (all_paths[i] != ':')
			i++;
		path = malloc(sizeof(char) * (i + 1 + ft_strlen(str)));
		if (!path)
			ft_exit("Error allocating memory\n");
		ft_strlcpy(path, all_paths, i + 1);
		ft_strlcat(path, "/", i + 2);
		ft_strlcat(path, str, i + 2 + ft_strlen(str));
		if (!access(path, X_OK))
			return(path);
		free(path);
		all_paths = all_paths + i + 1;
	}
	return (NULL);
}

void	ft_execute_cmd(char *str, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(str, ' ');
	if (!args)
	{
		write(2, "Error allocating memory\n", 22);
		exit(1);
	}
	path = ft_path(args[0], env);
	if (!path)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_free_tab(args);
		ft_exit("\n");
	}
	execve(path, args, env);
	free(path);
	ft_free_tab(args);
}

void	ft_do_cmd1(int	fd_pipe[2], char **av, char **env)
{
	int		fd1;

	fd1 = open(av[1], O_RDONLY);
	if (fd1 == -1)
	{
		ft_error();
		return ;
	}
	dup2(fd1, 0);
	dup2(fd_pipe[1], 1);
	close(fd_pipe[0]);
	ft_execute_cmd(av[2], env);
	close(fd1);
}

void	ft_do_cmd2(int	fd_pipe[], char **av, char **env)
{
	int		fd2;

	fd2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd2 == -1)
	{
		ft_error();
		exit(1);
	}
	dup2(fd2, 1);
	dup2(fd_pipe[0], 0);
	close(fd_pipe[1]);
	ft_execute_cmd(av[3], env);
	close(fd2);
}

int	main(int ac, char **av, char **env)
{
	int	fd_pipe[2];
	int	pid;

	if (ac != 5)
		return (ft_error());
	if(pipe(fd_pipe) == -1)
		return (ft_error());
	pid = fork();
	if (pid == -1)
		return(ft_error());
	else if(pid == 0)
		ft_do_cmd1(fd_pipe, av, env);
	else
		ft_do_cmd2(fd_pipe, av, env);
	return (0);
}