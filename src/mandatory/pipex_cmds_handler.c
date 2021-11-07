/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmds_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:13:28 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/07 19:01:12 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

static char	*get_path_var(char **envp)
{
	int		i;
	char	*p_var;

	i = 0;
	while(envp[i])
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
	int		i;
	char	**p_vars;
	char	*cmd_dup;
	char	*check_path;

	i = 0;
	p_vars = ft_split(p_var, ':');
	cmd_dup = ft_strdup(cmd);
	while (p_vars[i])
	{
		check_path = ft_strjoin(p_vars[i], "/");
		check_path = ft_append_str(&check_path, cmd);
		if (!access(check_path, F_OK))
		{
			free(cmd_dup);
			cmd_dup = NULL;
			return(check_path);
		}
		free(check_path);
		check_path = NULL;
		++i;
	}
	return (cmd_dup);
}

void	pipex_handle_cmds(char **argv, char **envp, t_pipe *pipeline)
{
	int		i;
	char	*p_var;

	i = 0;
	p_var = get_path_var(envp);
	while (i < 2)
	{
		pipeline->list_argvs[i] = ft_split(argv[i], ' ');
		pipeline->list_cmds[i] = get_cmd_path(pipeline->list_argvs[i][0], p_var);
		++i;
	}
	pipeline->envp = envp;
}
