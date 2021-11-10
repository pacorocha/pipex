/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:33:21 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/08 01:57:52 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

void	ft_child_process(char **argv, t_pipe *pipeline)
{
	pipeline->infile = pipex_open_file(argv[1], O_RDONLY, 0);
	pipex_redirect_fd(pipeline->infile, STDIN_FILENO);
	pipex_redirect_fd(pipeline->fd[1], STDOUT_FILENO);
	close(pipeline->fd[0]);
	pipex_run_execve(0, pipeline);
	exit(EXIT_SUCCESS);
}

void	ft_parent_process(char **argv, t_pipe *pipeline)
{
	int	status;

	waitpid(pipeline->child_pid, &status, 0);
	pipeline->outfile = pipex_open_file(argv[4], O_CREAT | O_WRONLY | O_TRUNC,
			0644);
	pipex_redirect_fd(pipeline->outfile, STDIN_FILENO);
	pipex_redirect_fd(pipeline->fd[0], STDOUT_FILENO);
	close(pipeline->fd[1]);
	pipex_run_execve(1, pipeline);
	exit(EXIT_SUCCESS);
}
