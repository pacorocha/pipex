/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:12:10 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/10 04:25:09 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include "../../libs/libft/libft.h"

typedef struct s_pipe {
	int		infile;
	int		outfile;
	int		fd[2];
	char	***p_argvs;
	char	**p_cmds;
	char	*paths;
	pid_t	pid_fc;
	pid_t	pnt_pid;
}						t_pipe;

void	print_error(int id_error);
void	init_pipeline(int argc, char **argv, char **envp, t_pipe *pipeline);
char	*get_path_var(char **envp);
void	pipex_handle_cmds(char **argv, char **envp, t_pipe *pipeline);
int		pipex_open_file(char *filename, int flags, mode_t mode);
pid_t	pipex_fork(void);
void	ft_child_process(char **argv, t_pipe *pipeline);
void	ft_parent_process(char **argv, t_pipe *pipeline);
void	pipex_redirect_fd(int src, int dest);
int		pipex_run_execve(int p, t_pipe *pipeline);

#endif