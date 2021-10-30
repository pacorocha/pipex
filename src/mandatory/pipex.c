/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:14:57 by jfrancis          #+#    #+#             */
/*   Updated: 2021/10/30 19:35:09 by coder            ###   ########.fr       */
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

	pipeline.infile = try_open_file(argv[1], O_RDONLY);
	close(pipeline.infile);
	return (0);
}
