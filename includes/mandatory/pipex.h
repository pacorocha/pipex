/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:12:10 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/07 18:10:41 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../../libs/libft/libft.h"

typedef struct s_pipe {
	int		infile;
	int		outfile;
	int		fd[2];
	char	***list_argvs;
	char	**list_cmds;
	char	**envp;
	pid_t	child_pid;
	pid_t	parent_pid;
}						t_pipe;

void	print_error(int id_error);
void	init_pipeline(int argc, char **argv, char **envp, t_pipe *pipeline);
void	pipex_handle_cmds(char **argv, char **envp, t_pipe *pipeline);
int		pipex_open_file(char *filename, int flags, mode_t mode);
pid_t	pipex_fork(void);
void	child_process(t_pipe pipeline);
void	redirect_fd(int src, int dest);

#endif