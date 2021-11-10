/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:14:57 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/10 03:56:43 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

void	close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipeline;

	init_pipeline(argc, argv, envp, &pipeline);
	pipeline.paths = get_path_var(envp);
	pipeline.cmd_paths = ft_split(pipex.paths, ':');
	pipeline.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, argv, envp);
	pipeline.pid2 = fork();
	if (pipeline.pid2 == 0)
		second_child(pipeline, argv, envp);
	close_pipes(&pipeline);
	waitpid(pipeline.pid1, NULL, 0);
	waitpid(pipeline.pid2, NULL, 0);
	parent_free(&pipex);
	return (0);
}
