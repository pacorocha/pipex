/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:20:25 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/06 22:34:25 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

void	redirect_fd(int src, int dest)
{
	if (dup2(src, dest) < 0)
		exit(EXIT_FAILURE);
	close(src);
}
