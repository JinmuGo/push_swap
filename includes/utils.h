/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:33:25 by jgo               #+#    #+#             */
/*   Updated: 2022/11/15 21:11:40 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// input.c
void				ps_parse(t_ps *ps, int argc, char **argv);
t_ps				*ps_init(t_ps *ps);
void				allocate_idx(t_st *st, t_st_node *new);

// error.c
void				print_error(void);

// utils.c
t_st_node			*deque_new(int content);
int					atoi_for_ps(const char *str);
t_bool				is_sorted(t_st *st);
t_bool				check_dup(t_st *st);
t_bool				check_fne(t_st_node *node, t_ps *ps);

// mandatory
	// utils.c
t_uint				get_max(t_uint num_a, t_uint num_b);
t_best				*find_best_min(t_uint *arr);
t_bool				check_fne(t_st_node *node, t_ps *ps);
t_uint				find_min_idx(t_st *st);

#endif
