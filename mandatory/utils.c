/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:27:02 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 21:02:31 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

t_uint	get_max(t_uint num_a, t_uint num_b)
{
	if (num_a > num_b)
		return (num_a);
	else
		return (num_b);
}

t_best	*find_best_min(t_uint *arr)
{
	int		i;
	int		size;
	t_best	*min;

	min = malloc(sizeof(t_best));
	if (!min)
		print_error();
	i = 0;
	size = 4;
	min->best_move_type = i;
	min->best_move_times = arr[i];
	while (++i < size)
	{
		if (arr[i] < min->best_move_times)
		{
			min->best_move_type = i;
			min->best_move_times = arr[i];
		}
	}
	return (min);
}

t_uint	find_min_idx(t_st *st)
{
	t_st_node	*node;
	t_uint		min_idx;

	node = st->node[FRONT];
	min_idx = U_INT_MAX;
	while (node != NULL)
	{
		if (node->idx < min_idx)
			min_idx = node->idx;
		node = node->next;
	}
	return (min_idx);
}
