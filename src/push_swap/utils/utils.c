/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:42:48 by jgo               #+#    #+#             */
/*   Updated: 2023/05/14 10:47:52 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

bool	check_fne(t_st_node *node, t_ps *ps)
{
	if (node->idx == ps->size - 1 || node->idx == 0)
		return (true);
	else
		return (false);
}

bool	check_dup(t_st *st)
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
				return (true);
			node = node->next;
		}
		first = first->next;
	}
	return (false);
}

bool	is_sorted(t_st *st)
{
	long long	max;
	t_st_node	*node;

	max = (-2147483648) - 1;
	node = st->node[FRONT];
	while (node)
	{
		if (max < node->data)
			max = node->data;
		else
			return (false);
		node = node->next;
	}
	return (true);
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
	long long	prev;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	prev = result;
	if (!str[i] || ft_isspace(str[i]))
		print_error();
	if (str[i] == '-')
		sign *= -1;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || !ft_isinteger(result) || result < prev)
			print_error();
		result = result * 10 + str[i++] - '0';
		prev = result;
	}
	if (!ft_isinteger(result * sign))
		print_error();
	return (result * sign);
}
