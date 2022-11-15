/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_right_place.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:17:48 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 20:57:30 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

t_uint	get_diff_abs(t_uint num_a, t_uint num_b)
{
	if (num_a > num_b)
		return (num_a - num_b);
	else
		return (num_b - num_a);
}

void	set_closest_number_to_top(t_greedy	*greedy, t_uint pos, t_st *a)
{
	if (pos == 0)
	{
		greedy->rotate[RA] = 0;
		greedy->rotate[RRA] = 0;
	}
	else
	{
		greedy->rotate[RA] = pos;
		greedy->rotate[RRA] = (a->size) - pos;
	}
}

void	set_closest_number_to_bottom(t_greedy *greedy, t_uint pos, t_st *a)
{
	if (pos == (a->size - 1))
	{
		greedy->rotate[RA] = 0;
		greedy->rotate[RRA] = 0;
	}
	else
	{
		greedy->rotate[RA] = pos + 1;
		greedy->rotate[RRA] = ((a->size) - (pos + 1));
	}
}

t_num	*get_proximate_num(t_uint curr_idx, t_st *a)
{
	int				node_pos;
	int				diff_abs;
	int				min_diff_abs;
	t_st_node		*curr_node;
	t_num			*proximate_node;

	proximate_node = malloc(sizeof(t_num));
	if (!proximate_node)
		print_error();
	node_pos = 0;
	min_diff_abs = 0;
	curr_node = a->node[FRONT];
	while (curr_node != NULL)
	{
		diff_abs = get_diff_abs(curr_idx, curr_node->idx);
		if ((node_pos == 0) || (diff_abs < min_diff_abs))
		{
			min_diff_abs = diff_abs;
			proximate_node->idx = curr_node->idx;
			proximate_node->pos = node_pos;
		}
		curr_node = curr_node->next;
		node_pos++;
	}
	return (proximate_node);
}

void	a_to_right_place(t_greedy *greedy, t_st *a, t_uint curr_idx)
{
	t_num	*proximate_node;

	if (a->size == 0)
	{
		greedy->rotate[RA] = 0;
		greedy->rotate[RRA] = 0;
		return ;
	}
	proximate_node = get_proximate_num(curr_idx, a);
	if (proximate_node->idx > curr_idx)
		set_closest_number_to_top(greedy, proximate_node->pos, a);
	else
		set_closest_number_to_bottom(greedy, proximate_node->pos, a);
	free(proximate_node);
}
