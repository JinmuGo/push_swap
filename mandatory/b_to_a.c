/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:45:56 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 21:02:37 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

void	b_to_edge(t_greedy *greedy, t_st *b, t_uint node_pos)
{
	if (node_pos == 0)
	{
		greedy->rotate[RB] = 0;
		greedy->rotate[RRB] = 0;
	}
	else
	{
		greedy->rotate[RB] = node_pos;
		greedy->rotate[RRB] = (b->size) - node_pos;
	}
}

t_best	*find_min_rotate(t_greedy *greedy)
{
	t_uint	rotation_logic[4];

	rotation_logic[RA_RB] = get_max(greedy->rotate[RA], greedy->rotate[RB]);
	rotation_logic[RRA_RRB] = get_max(greedy->rotate[RRA], greedy->rotate[RRB]);
	rotation_logic[RA_RRB] = greedy->rotate[RA] + greedy->rotate[RRB];
	rotation_logic[RRA_RB] = greedy->rotate[RRA] + greedy->rotate[RB];
	return (find_best_min(rotation_logic));
}

void	allocate_rotate(t_rotate *rotate, t_greedy *greedy, t_uint best_move)
{
	rotate->best_move = best_move;
	if (rotate->best_move == RA_RB)
	{
		rotate->a_rotate = greedy->rotate[RA];
		rotate->b_rotate = greedy->rotate[RB];
	}
	if (rotate->best_move == RA_RRB)
	{
		rotate->a_rotate = greedy->rotate[RA];
		rotate->b_rotate = greedy->rotate[RRB];
	}
	if (rotate->best_move == RRA_RB)
	{
		rotate->a_rotate = greedy->rotate[RRA];
		rotate->b_rotate = greedy->rotate[RB];
	}
	if (rotate->best_move == RRA_RRB)
	{
		rotate->a_rotate = greedy->rotate[RRA];
		rotate->b_rotate = greedy->rotate[RRB];
	}
}

void	find_best_case(t_greedy *greedy, t_ps *ps, t_rotate *rotate)
{
	t_best		*best_case;
	t_st_node	*node;
	t_uint		node_pos;
	t_uint		best_idx;

	node_pos = 0;
	node = ps->b.node[FRONT];
	while (node != NULL)
	{
		b_to_edge(greedy, &ps->b, node_pos);
		a_to_right_place(greedy, &ps->a, node->idx);
		best_case = find_min_rotate(greedy);
		if ((node_pos == 0) || \
			(greedy->best_move > best_case->best_move_times) || \
			((greedy->best_move == best_case->best_move_times) && \
			(node->idx > best_idx)))
		{
			best_idx = node->idx;
			greedy->best_move = best_case->best_move_times;
			allocate_rotate(rotate, greedy, best_case->best_move_type);
		}
		node_pos++;
		node = node->next;
		free(best_case);
	}
}

void	b_to_a(t_ps *ps)
{
	t_greedy	*greedy;
	t_rotate	*rotate;

	greedy = malloc(sizeof(t_greedy));
	if (!greedy)
		print_error();
	rotate = malloc(sizeof(t_rotate));
	if (!rotate)
		print_error();
	if (ps->a.node[FRONT]->idx == 0)
		command(ps, "sa\n");
	while (ps->b.size != 0)
	{
		find_best_case(greedy, ps, rotate);
		rotate_stack_ab(ps, rotate);
		command(ps, "pa\n");
	}
	free(greedy);
	free(rotate);
	align_stack_a(ps);
}
