/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:14:57 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/07 01:08:49 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipeline;

	init_pipeline(argc, argv, envp, &pipeline);
	if (pipe(pipeline.fd) == -1)
	{
		print_error(3);
		exit(EXIT_FAILURE);
	}
	pipeline.child_pid = pipex_fork();
	if (pipeline.child_pid == 0)
		printf("child_pid: %i\n", pipeline.child_pid);
	close(pipeline.infile);
	return (0);
}
