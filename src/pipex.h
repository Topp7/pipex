/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:27:07 by stopp             #+#    #+#             */
/*   Updated: 2024/04/26 15:12:28 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "lib/ft_printf.h"
# include <time.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		out_fd;
	int		here_doc;
	int		cmd_count;
	int		child_status;
	char	**paths;
	char	**cmd;
}	t_pipex;

int		init_data(int argc, char *argv[], t_pipex *data, char **envp);
void	get_cmd(char **argv, t_pipex *data, int i);
int		get_paths(char **envp, t_pipex *data);
char	*get_cmdpath(t_pipex *data, char *cmd);
void	cleanup(t_pipex *data);
void	free_dp(char **dp);

#endif
