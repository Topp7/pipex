/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_exec_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:52:42 by stopp             #+#    #+#             */
/*   Updated: 2024/04/26 15:53:06 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	get_cmd(char **argv, t_pipex *data, int i)
{
	int		start_arg;

	if (data->here_doc)
		start_arg = 3;
	else
		start_arg = 2;
	data->cmd = ft_split(argv[i + start_arg], ' ');
	if (!data->cmd)
		return ;
	return ;
}

char	*ft_getenv(char **envp, char *name)
{
	int		i;
	char	*path;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, 5) == 0)
			path = envp[i] + 5;
		i++;
	}
	return (path);
}

int	get_paths(char **envp, t_pipex *data)
{
	int		i;
	char	*path;

	path = NULL;
	i = 0;
	path = ft_getenv(envp, "PATH=");
	if (path)
	{
		data->paths = ft_split(path, ':');
		if (!data->paths)
			return (0);
		while (data->paths[i])
		{
			path = data->paths[i];
			data->paths[i] = ft_strjoin(path, "/");
			free(path);
			if (!data->paths[i])
				return (cleanup(data), 0);
			i++;
		}
		return (1);
	}
	else
		return (0);
}

char	*get_cmdpath(t_pipex *data, char *cmd)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (data->paths[i])
	{
		cmd_path = ft_strjoin(data->paths[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}
