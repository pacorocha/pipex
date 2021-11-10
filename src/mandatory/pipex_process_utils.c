/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:20:25 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/07 23:47:24 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

void	pipex_redirect_fd(int src, int dest)
{
	if (dup2(src, dest) < 0)
		exit(EXIT_FAILURE);
	close(src);
}

int	pipex_run_execve(int p, t_pipe *pipeline)
{
	if (execve(pipeline->p_cmds[p], pipeline->p_argvs[p], pipeline->envp) < 0)
	{
		perror(pipeline->p_cmds[p]);
		exit(EXIT_FAILURE);
	}
	return (1);
}
