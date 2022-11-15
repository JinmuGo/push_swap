/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:38:20 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 20:57:56 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

void	align_stack_a(t_ps *ps)
{
	const t_st	*a = &ps->a;
	t_uint		first_pos;
	t_st_node	*node;

	first_pos = 0;
	node = a->node[FRONT];
	while (node && node->idx != 0)
	{
		node = node -> next;
		first_pos++;
	}
	if (first_pos > (a->size / 2))
		while (first_pos++ < a->size)
			command(ps, "rra\n");
	else
		while (first_pos-- > 0)
			command(ps, "ra\n");
}
