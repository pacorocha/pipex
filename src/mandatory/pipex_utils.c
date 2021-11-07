/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:28:44 by coder             #+#    #+#             */
/*   Updated: 2021/11/07 17:18:26 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

void	init_pipeline(int argc, char **argv, char **envp, t_pipe *pipeline)
{
	if (argc < 5)
		print_error(1);
	if (argc > 5)
		print_error(2);
	pipeline->infile = 0;
	pipeline->outfile = 0;
	pipex_handle_cmds(argv, envp, pipeline);
	pipeline->infile = pipex_open_file(argv[1], O_RDONLY, 0);
	pipeline->outfile = pipex_open_file(argv[4], O_CREAT | O_WRONLY | O_TRUNC,
			0644);
}

int	pipex_open_file(char *filename, int flags, mode_t mode)
{
	int	file_fd;

	file_fd = open(filename, flags, mode);
	if (file_fd < 0)
		print_error(4);
	return (file_fd);
}

pid_t	pipex_fork(void)
{
	pid_t	forked;

	forked = fork();
	if (forked < 0)
	{
		print_error(5);
	}
	return (forked);
}
