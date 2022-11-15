/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:54:55 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 21:08:01 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_st *from, t_st *to)
{
	t_st_node	*node;

	if (from->size < 1)
		return (0);
	node = deque(from, FRONT);
	enque(to, FRONT, node);
	return (1);
}

int	swap(t_st *st)
{
	t_st_node	*node[2];

	if (st->size < 2)
		return (0);
	node[0] = deque(st, FRONT);
	node[1] = deque(st, FRONT);
	enque(st, FRONT, node[0]);
	enque(st, FRONT, node[1]);
	return (1);
}

int	rotate(t_st *st)
{
	t_st_node	*node;

	if (st->size < 1)
		return (0);
	node = deque(st, FRONT);
	enque(st, REAR, node);
	return (1);
}

int	reverse_rotate(t_st *st)
{
	t_st_node	*node;

	if (st->size < 1)
		return (0);
	node = deque(st, REAR);
	enque(st, FRONT, node);
	return (1);
}

int	command(t_ps *ps, char *cmd)
{
	if (cmd_compare(cmd, "sa\n", 4))
		return (swap(&ps->a));
	if (cmd_compare(cmd, "sb\n", 4))
		return (swap(&ps->b));
	if (cmd_compare(cmd, "ss\n", 4))
		return (swap(&ps->a) && swap(&ps->b));
	if (cmd_compare(cmd, "pa\n", 4))
		return (push(&ps->b, &ps->a));
	if (cmd_compare(cmd, "pb\n", 4))
		return (push(&ps->a, &ps->b));
	if (cmd_compare(cmd, "ra\n", 4))
		return (rotate(&ps->a));
	if (cmd_compare(cmd, "rb\n", 4))
		return (rotate(&ps->b));
	if (cmd_compare(cmd, "rr\n", 4))
		return (rotate(&ps->a) && rotate(&ps->b));
	if (cmd_compare(cmd, "rra\n", 5))
		return (reverse_rotate(&ps->a));
	if (cmd_compare(cmd, "rrb\n", 5))
		return (reverse_rotate(&ps->b));
	if (cmd_compare(cmd, "rrr\n", 5))
		return (reverse_rotate(&ps->a) && reverse_rotate(&ps->b));
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
