/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:41:59 by jgo               #+#    #+#             */
/*   Updated: 2023/06/06 14:29:09 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		return (swap(&ps->a));
	if (ft_strncmp(cmd, "sb\n", 3) == 0)
		return (swap(&ps->b));
	if (ft_strncmp(cmd, "ss\n", 3) == 0)
		return (swap(&ps->a) && swap(&ps->b));
	if (ft_strncmp(cmd, "pa\n", 3) == 0)
		return (push(&ps->b, &ps->a));
	if (ft_strncmp(cmd, "pb\n", 3) == 0)
		return (push(&ps->a, &ps->b));
	if (ft_strncmp(cmd, "ra\n", 3) == 0)
		return (rotate(&ps->a));
	if (ft_strncmp(cmd, "rb\n", 3) == 0)
		return (rotate(&ps->b));
	if (ft_strncmp(cmd, "rr\n", 3) == 0)
		return (rotate(&ps->a) && rotate(&ps->b));
	if (ft_strncmp(cmd, "rra\n", 4) == 0)
		return (reverse_rotate(&ps->a));
	if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		return (reverse_rotate(&ps->b));
	if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		return (reverse_rotate(&ps->a) && reverse_rotate(&ps->b));
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
