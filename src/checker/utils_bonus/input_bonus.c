/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:06:38 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 20:53:24 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	allocate_idx(t_st *st, t_st_node *new)
{
	const int		val = new->data;
	t_st_node		*node;
	unsigned int	new_idx;

	node = st->node[FRONT];
	new_idx = 0;
	while (node != new)
	{
		if (node->data > val)
			node->idx++;
		else
			new_idx++;
		node = node->next;
	}
	new->idx = new_idx;
}

t_ps	*ps_init(t_ps *ps)
{
	ps = malloc(sizeof(t_ps));
	if (!ps)
		print_error();
	ps->size = 0;
	ps->a.size = 0;
	ps->b.size = 0;
	ps->a.node[FRONT] = NULL;
	ps->b.node[FRONT] = NULL;
	ps->a.node[REAR] = NULL;
	ps->b.node[REAR] = NULL;
	return (ps);
}

void	ps_parse(t_ps *ps, int argc, char **argv)
{
	t_st_node	*node;
	char		**char_arr;
	int			content;
	int			idx;
	int			inner_idx;

	idx = 0;
	while (idx < argc)
	{
		char_arr = ft_split(argv[idx++], ' ');
		if (!char_arr || char_arr[0] == 0)
			print_error();
		inner_idx = 0;
		while (char_arr[inner_idx])
		{
			content = atoi_for_ps(char_arr[inner_idx++]);
			node = deque_new(content);
			enque(&ps->a, REAR, node);
			allocate_idx(&ps->a, node);
		}
		ft_free_all_arr(char_arr);
	}
	if (check_dup(&ps->a))
		print_error();
	ps->size = ps->a.size + ps->b.size;
}
