/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:12:10 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/06 02:57:56 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../../libs/libft/libft.h"

typedef struct s_pipe {
	int		infile;
	int		outfile;
	int		fd[2];
	pid_t	child_pid;
	pid_t	parent_pid;
}						t_pipe;

void	init_pipeline(t_pipe *pipeline);
void	print_error(int id_error);
int		pipex_open_file(char *filename, int flags, mode_t mode);
pid_t	pipex_fork(void);

#endif