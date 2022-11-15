/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:34:53 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 21:11:49 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

void	move_partition(t_uint sidx, t_uint midx, t_uint eidx, t_ps *ps)
{
	const t_uint		size = ps->a.size;
	t_st_node			*node;
	t_st_node			*next;
	t_uint				i;

	node = ps->a.node[FRONT];
	i = -1;
	while (++i < size)
	{
		next = node->next;
		if (midx <= node->idx && node->idx < eidx \
			&& !check_fne(node, ps))
		{
			command(ps, "pb\n");
			command(ps, "rb\n");
		}
		else if (sidx <= node->idx && node->idx < midx \
			&& !check_fne(node, ps))
			command(ps, "pb\n");
		else
			command(ps, "ra\n");
		node = next;
	}
}

void	init_a_to_b(t_ps *ps)
{
	const t_uint	size = ps->a.size;
	int				step;
	t_uint			sidx;
	t_uint			midx;
	t_uint			eidx;

	step = 6;
	eidx = size;
	while (step > 1)
	{
		step -= 2;
		midx = (size * (step + 1)) / 6;
		sidx = (size * step) / 6;
		move_partition(sidx, midx, eidx, ps);
		eidx = sidx;
	}
}

void	sort_big(t_ps *ps)
{
	init_a_to_b(ps);
	b_to_a(ps);
}
