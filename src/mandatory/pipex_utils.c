/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:28:44 by coder             #+#    #+#             */
/*   Updated: 2021/11/10 03:53:37 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

void	init_pipeline(int argc, char **argv, char **envp, t_pipe *pipeline)
{
	if (argc < 5)
		print_error(1);
	if (argc > 5)
		print_error(2);
	pipeline->infile = open(argv[1], O_RDONLY);
	if (pipeline->infile < 0)
		print_error(4);
	pipeline->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipeline->outfile < 0)
		print_error(4);
	if (pipe(pipeline->fd) < 0)
		print_error(3);
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
