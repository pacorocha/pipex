/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmds_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:13:28 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/10 03:41:38 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

char	*get_path_var(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
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
			return (check_path);
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
	while (i < 5)
	{
		pipeline->p_argvs[i] = ft_split(argv[i], ' ');
		pipeline->p_cmds[i] = get_cmd_path(pipeline->p_argvs[i][0], p_var);
		++i;
	}
	pipeline->envp = envp;
}
