/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:14:57 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/06 02:57:37 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

int main(int argc, char **argv)
{
	t_pipe	pipeline;

	init_pipeline(&pipeline);
	if (argc < 5)
		print_error(1);
	if (argc > 5)
		print_error(2);

	if (pipe(pipeline.fd) == -1)
	{
		print_error(3);
		exit(EXIT_FAILURE);
	}

	pipeline.infile = pipex_open_file(argv[1], O_RDONLY, 0);
	pipeline.outfile = pipex_open_file(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);

	pipeline.child_pid = pipex_fork();

	close(pipeline.infile);
	return (0);
}
