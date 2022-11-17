/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:01:14 by jgo               #+#    #+#             */
/*   Updated: 2022/11/17 11:01:17 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"
# include "get_next_line_bonus.h"
# include "ft_printf.h"

# define U_INT_MAX 4294967295

# define RA_RB 0
# define RRA_RB 1
# define RA_RRB 2
# define RRA_RRB 3

# define RA 0
# define RB 1
# define RRA 2
# define RRB 3

typedef struct s_pushswap	t_ps;
typedef struct s_stack		t_st;
typedef struct s_stack_node	t_st_node;

typedef struct s_greedy		t_greedy;
typedef struct s_num		t_num;
typedef struct s_rotate		t_rotate;
typedef struct s_best		t_best;

typedef unsigned int		t_uint;

struct s_stack_node
{
	int						data;
	unsigned int			idx;
	struct s_stack_node		*prev;
	struct s_stack_node		*next;
};

struct s_stack
{
	unsigned int			size;
	struct s_stack_node		*node[2];
};

struct s_pushswap
{
	unsigned int		size;
	struct s_stack		a;
	struct s_stack		b;
};

struct s_greedy
{
	t_uint		rotate[4];
	t_uint		best_move;
};

struct s_rotate
{
	t_uint	best_move;
	t_uint	a_rotate;
	t_uint	b_rotate;
};

struct s_best
{
	t_uint	best_move_type;
	t_uint	best_move_times;
};

struct s_num
{
	t_uint	idx;
	t_uint	pos;
};

enum e_rear
{
	FRONT = 0,
	REAR = 1
};

enum e_status
{
	SUCCESS = 1,
	FAIL = 0
};

// dequeue/
	// enque.c
void		enque(t_st *st, enum e_rear rear, t_st_node *new);

	// deque.c
t_st_node	*deque(t_st *st, enum e_rear rear);

// commands/
	// commands.c
int			command(t_ps *ps, char *cmd);
t_bool		cmd_compare(char *cmd, char *src, int size);

//  mandatory/
	// less_than_five.c
void		sort_small(t_ps *ps);

	// sort.c
void		sort_big(t_ps *ps);

	// b_to_a.c
void		b_to_a(t_ps *ps);

	// a_to_right_place.c
void		a_to_right_place(t_greedy *greedy, t_st *a, t_uint curr_idx);

	// rotate_stack_ab.c
void		rotate_stack_ab(t_ps *ps, t_rotate *rotate);

	// align_stack_a.c	
void		align_stack_a(t_ps *ps);

#endif