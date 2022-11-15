/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:48:52 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 20:54:11 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_st_node	*deque_pop_front(t_st *st)
{
	t_st_node	*node;

	if (!st->node[FRONT])
		return (NULL);
	node = st->node[FRONT];
	st->node[FRONT] = node->next;
	if (st->node[FRONT] && st->node[FRONT]->prev)
		st->node[FRONT]->prev = NULL;
	return (node);
}

t_st_node	*deque_pop_rear(t_st *st)
{
	t_st_node	*node;

	if (!st->node[REAR])
		return (NULL);
	node = st->node[REAR];
	st->node[REAR] = st->node[REAR]->prev;
	if (st->node[REAR] && st->node[REAR]->next)
		st->node[REAR]->next = NULL;
	return (node);
}

t_st_node	*deque(t_st *st, enum e_rear rear)
{
	t_st_node	*node;

	if (!st)
		return (NULL);
	if (rear == FRONT)
		node = deque_pop_front(st);
	else
		node = deque_pop_rear(st);
	st->size--;
	node->next = NULL;
	node->prev = NULL;
	if (!st->size)
	{
		st->node[FRONT] = NULL;
		st->node[REAR] = NULL;
	}
	return (node);
}
