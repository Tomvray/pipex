/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <tvray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:59:57 by tvray             #+#    #+#             */
/*   Updated: 2023/05/08 15:19:45 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

char	*ft_new_path(char *all_paths, char **ptr_path, char *cmd, int i)
{
	char	*path;

	path = malloc(sizeof(char) * (i + 2 + ft_strlen(cmd)));
	if (!path)
		ft_exit("Error allocating memory\n", 1);
	ft_strlcpy(path, all_paths, i + 1);
	ft_strlcat(path, "/", i + 2);
	ft_strlcat(path, cmd, i + 2 + ft_strlen(cmd));
	if (!access(path, X_OK))
	{
		*ptr_path = path;
		return (path);
	}
	free(path);
	ptr_path = NULL;
	return (NULL);
}

char	*ft_path(char	*cmd, char **env)
{
	char	*all_paths;
	char	*path;
	int		i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		ft_exit("path not in env\n", 1);
	all_paths = env[i] + 5;
	while (*all_paths)
	{
		i = 0;
		while (all_paths[i] && all_paths[i] != ':')
			i++;
		path = ft_new_path(all_paths, &path, cmd, i);
		if (path)
			return (path);
		all_paths = all_paths + i + 1;
	}
	if (!access(cmd, X_OK))
		return (ft_strdup(cmd));
	return (NULL);
}
