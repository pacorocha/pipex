/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmds_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:13:28 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/07 18:18:18 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

static char	*get_path_var(char **envp)
{
	int		i;
	char	*p_var;

	i = 0;
	while(envp[p])
	{
		p_var = ft_strnstr(envp[i], "PATH", 4);
		if (p_var)
			return(p_var);
		++i;
	}
	return (NULL);
}

static char	*get_cmd_path(char *cmd, char *p_var)
{
	char	**p_vars;
	int		i;
	ft_strdup();
}

void	pipex_handle_cmds(char **argv, char **envp, t_pipe *pipeline)
{
	int		i;
	char	*p_var;

	i = 0;
	p_var = get_path_var(envp);
	while (i < 2)
	{
		pipeline.list_argvs[i] = ft_split(argv[i], ' ');
		pipeline.list_cmds[i] = get_cmd_path(pipeline.list_argvs[i][0], p_var);
		++i;
	}
	pipeline.envp = envp;
}
