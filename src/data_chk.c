/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_chk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:28:31 by soren             #+#    #+#             */
/*   Updated: 2024/04/26 15:15:55 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(int argc, char *argv[], t_pipex *data)
{
	int	in_fd;

	if (access(argv[1], R_OK) == -1)
	{
		ft_printf("Access to infile denied");
		return (0);
	}
	in_fd = open(argv[1], O_RDONLY);
	if (!in_fd)
		return (0);
	data->cmd_count = argc - 3;
	dup2(in_fd, STDIN_FILENO);
	close(in_fd);
	return (1);
}

static int	here_doc(char *argv[])
{
	char	*buf;
	int		fd[2];

	if (pipe(fd) == -1)
		return (0);
	while (1)
	{
		buf = get_next_line(STDIN_FILENO);
		if (ft_strncmp(buf, argv[2], ft_strlen(buf)) == 10)
			break ;
		write(fd[1], buf, ft_strlen(buf));
		free(buf);
	}
	free(buf);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	return (1);
}

int	init_data(int argc, char *argv[], t_pipex *data, char **envp)
{
	data->cmd = NULL;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
			return (0);
		data->here_doc = 1;
		if (!here_doc(argv))
			return (0);
		data->cmd_count = argc - 4;
	}
	else if (!open_infile(argc, argv, data))
		return (0);
	data->out_fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (!data->out_fd)
		return (0);
	if (!get_paths(envp, data))
		return (0);
	return (1);
}

void	free_dp(char **dp)
{
	int	i;

	i = 0;
	if (dp != NULL)
	{
		while (dp[i])
			free(dp[i++]);
		free(dp);
	}
}

void	cleanup(t_pipex *data)
{
	free_dp(data->paths);
	close(data->out_fd);
	if (data->cmd)
		free_dp(data->cmd);
	free(data);
	return ;
}
