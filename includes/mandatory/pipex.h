/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:12:10 by jfrancis          #+#    #+#             */
/*   Updated: 2021/10/30 19:33:16 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../../libs/libft/libft.h"

typedef struct s_pipe {
	int	infile;
	int	outfile;
}						t_pipe;

void	init_pipeline(t_pipe *pipeline);
void	print_error(int id_error);
int		try_open_file(char *filename, int flags);

#endif