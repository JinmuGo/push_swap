/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:33:50 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 20:58:50 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

void	up_to_least_idx(t_ps *ps)
{
	const t_st		*a = &ps->a;
	const t_uint	min_idx = find_min_idx(&ps->a);
	t_uint			least_pos;
	t_st_node		*node;

	least_pos = 0;
	node = a->node[FRONT];
	while (node && node->idx != min_idx)
	{
		node = node -> next;
		least_pos++;
	}
	if (least_pos > (a->size / 2))
		while (least_pos++ < a->size)
			command(ps, "rra\n");
	else
		while (least_pos-- > 0)
			command(ps, "ra\n");
}

void	sort_three(t_ps *ps)
{
	const int	first = ps->a.node[FRONT]->data;
	const int	middle = ps->a.node[FRONT]->next->data;
	const int	last = ps->a.node[FRONT]->next->next->data;

	if (is_sorted(&ps->a))
		return ;
	if (first > middle && middle > last && first > last)
	{
		command(ps, "sa\n");
		command(ps, "rra\n");
	}
	if (first < middle && middle > last && first < last)
	{
		command(ps, "rra\n");
		command(ps, "sa\n");
	}
	if (first > middle && middle < last && first < last)
		command(ps, "sa\n");
	if (first < middle && middle > last && first > last)
		command(ps, "rra\n");
	if (first > middle && middle < last && first > last)
		command(ps, "ra\n");
}

void	sort_four(t_ps *ps)
{
	if (is_sorted(&ps->a))
		return ;
	up_to_least_idx(ps);
	command(ps, "pb\n");
	sort_three(ps);
	command(ps, "pa\n");
}

void	sort_five(t_ps *ps)
{
	if (is_sorted(&ps->a))
		return ;
	up_to_least_idx(ps);
	command(ps, "pb\n");
	sort_four(ps);
	command(ps, "pa\n");
}

void	sort_small(t_ps *ps)
{
	if (ps->size == 2)
		command(ps, "sa\n");
	if (ps->size == 3)
		sort_three(ps);
	if (ps->size == 4)
		sort_four(ps);
	if (ps->size == 5)
		sort_five(ps);
}
