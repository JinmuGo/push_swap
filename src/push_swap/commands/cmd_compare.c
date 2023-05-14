/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:10:07 by jgo               #+#    #+#             */
/*   Updated: 2023/05/14 10:47:52 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	cmd_compare(char *cmd, char *src, int size)
{
	if (ft_strncmp(cmd, src, size) == 0)
	{
		write(1, src, size - 1);
		return (true);
	}
	return (false);
}
