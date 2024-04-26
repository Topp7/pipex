/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:26:45 by stopp             #+#    #+#             */
/*   Updated: 2024/04/26 17:12:23 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(t_pipex *data, char **envp)
{
	char	*cmdpath;

	cmdpath = get_cmdpath(data, data->cmd[0]);
	execve(cmdpath, data->cmd, envp);
	perror("execution failed");
	return ;
}

int	pipe_cmds(t_pipex *data, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		exec_cmd(data, envp);
		return (0);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	return (1);
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	*data;
	int		i;

	i = -1;
	if (argc < 5)
		return (0);
	data = malloc(sizeof(t_pipex));
	if (!data)
		return (0);
	if (!init_data(argc, argv, data, envp))
		return (0);
	while (++i < data->cmd_count - 1)
	{
		get_cmd(argv, data, i);
		if (!pipe_cmds(data, envp))
			return (cleanup(data), 0);
		free_dp(data->cmd);
	}
	dup2(data->out_fd, STDOUT_FILENO);
	get_cmd(argv, data, i);
	exec_cmd(data, envp);
	cleanup(data);
	return (0);
}
