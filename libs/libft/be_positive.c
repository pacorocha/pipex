/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_positive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:09:51 by jfrancis          #+#    #+#             */
/*   Updated: 2021/06/06 17:47:57 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	be_positive(long int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}
