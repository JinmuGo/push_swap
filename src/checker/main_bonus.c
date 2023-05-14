/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:48:31 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 21:07:53 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	checker(t_ps *ps)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		command(ps, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
	if (is_sorted(&ps->a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	ps = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	ps = ps_init(ps);
	ps_parse(ps, argc - 1, argv + 1);
	checker(ps);
	exit(EXIT_SUCCESS);
}
