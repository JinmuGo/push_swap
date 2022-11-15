/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:42:48 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 21:01:45 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

t_bool	check_fne(t_st_node *node, t_ps *ps)
{
	if (node->idx == ps->size - 1 || node->idx == 0)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	check_dup(t_st *st)
{
	t_st_node	*first;
	t_st_node	*node;

	first = st->node[FRONT];
	while (first)
	{
		node = first->next;
		while (node)
		{
			if (first->data == node->data)
				return (TRUE);
			node = node->next;
		}
		first = first->next;
	}
	return (FALSE);
}

t_bool	is_sorted(t_st *st)
{
	long		max;
	t_st_node	*node;

	max = (-2147483648) - 1;
	node = st->node[FRONT];
	while (node)
	{
		if (max < node->data)
			max = node->data;
		else
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

t_st_node	*deque_new(int content)
{
	t_st_node	*node;

	node = malloc(sizeof(t_st_node));
	if (!node)
		print_error();
	node -> next = NULL;
	node -> prev = NULL;
	node -> data = content;
	return (node);
}

int	atoi_for_ps(const char *str)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	if (!str[i] || ft_isspace(str[i]))
		print_error();
	if (str[i] == '-')
		sign *= -1;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_error();
		result = result * 10 + str[i++] - '0';
	}
	if (!ft_isinteger(result * sign))
		print_error();
	return (result * sign);
}
