/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:28:44 by coder             #+#    #+#             */
/*   Updated: 2021/11/06 02:59:32 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

void	init_pipeline(t_pipe *pipeline)
{
	pipeline->infile = 0;
	pipeline->outfile = 0;
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
}
