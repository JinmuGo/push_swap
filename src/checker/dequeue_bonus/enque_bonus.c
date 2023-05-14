/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enque_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:59:57 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 17:18:11 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	enque_front(t_st *st, t_st_node *new)
{
	if (!st->node[FRONT])
		st->node[FRONT] = new;
	else
	{
		new->next = st->node[FRONT];
		st->node[FRONT]->prev = new;
		st->node[FRONT] = new;
	}
}

void	enque_rear(t_st *st, t_st_node *new)
{
	if (!st->node[REAR])
		st->node[REAR] = new;
	else
	{
		new->prev = st->node[REAR];
		st->node[REAR]->next = new;
		st->node[REAR] = new;
	}
}

void	enque(t_st *st, enum e_rear rear, t_st_node *new)
{
	if (!new)
		return ;
	st->size++;
	if (!st->node[FRONT] && !st->node[REAR])
	{
		st->node[FRONT] = new;
		st->node[REAR] = new;
		return ;
	}
	if (rear == FRONT)
		enque_front(st, new);
	else
		enque_rear(st, new);
	if (st->node[FRONT] && st->node[FRONT]->prev)
		st->node[FRONT]->prev = NULL;
	if (st->node[REAR] && st->node[REAR]->next)
		st->node[REAR]->next = NULL;
}
