/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:36:50 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 21:08:09 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

void	push_swap(t_ps *ps)
{
	if (is_sorted(&ps->a))
		return ;
	if (ps->size <= 5)
		sort_small(ps);
	else
		sort_big(ps);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	ps = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	ps = ps_init(ps);
	ps_parse(ps, argc - 1, argv + 1);
	push_swap(ps);
	exit(EXIT_SUCCESS);
}
