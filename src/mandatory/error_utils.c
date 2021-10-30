/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 02:15:00 by jfrancis          #+#    #+#             */
/*   Updated: 2021/10/30 19:33:41 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

void	print_error(int id_error)
{
	char	*error_msg;

	error_msg = 0;
	if (id_error == 1)
		error_msg = "Too few arguments";
	else if (id_error == 2)
		error_msg = "Too many arguments";
	ft_putstr_fd(error_msg, 1);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

int	try_open_file(char *filename, int flags)
{
	int	file_fd;

	file_fd = open(filename, flags);
	if (file_fd < 0)
		perror(filename);
	return (file_fd);
}
