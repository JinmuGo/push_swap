/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:10:07 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 17:19:56 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	cmd_compare(char *cmd, char *src, int size)
{
	if (ft_strncmp(cmd, src, size) == 0)
	{
		write(1, src, size - 1);
		return (TRUE);
	}
	return (FALSE);
}
