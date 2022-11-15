/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:02:07 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 21:07:22 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		if (!ft_isdigit(str[i]) || !ft_isinteger(result))
			print_error();
		result = result * 10 + str[i++] - '0';
	}
	if (!ft_isinteger(result))
		print_error();
	return (result * sign);
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

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
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
