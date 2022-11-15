/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:22:39 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 21:02:42 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

void	rotate_both(t_rotate *rotate, t_ps *ps)
{
	if (rotate->best_move == RA_RRB || \
		rotate->best_move == RRA_RB)
		return ;
	while ((rotate->a_rotate != 0) && (rotate->b_rotate != 0))
	{
		if (rotate->best_move == RA_RB)
			command(ps, "rr\n");
		else
			command(ps, "rrr\n");
		(rotate->a_rotate)--;
		(rotate->b_rotate)--;
	}
}

void	rotate_stack_a(t_rotate *rotate, t_ps *ps)
{
	while (rotate->a_rotate != 0)
	{
		if (rotate->best_move == RA_RB || \
				rotate->best_move == RA_RRB)
			command(ps, "ra\n");
		else
			command(ps, "rra\n");
		(rotate->a_rotate)--;
	}
}

void	rotate_stack_b(t_rotate *rotate, t_ps *ps)
{
	while (rotate->b_rotate != 0)
	{
		if (rotate->best_move == RRA_RB || \
				rotate->best_move == RA_RB)
			command(ps, "rb\n");
		else
			command(ps, "rrb\n");
		(rotate->b_rotate)--;
	}
}

void	rotate_stack_ab(t_ps *ps, t_rotate *rotate)
{
	rotate_both(rotate, ps);
	rotate_stack_a(rotate, ps);
	rotate_stack_b(rotate, ps);
}
