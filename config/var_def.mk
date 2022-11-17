# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    var_def.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 14:02:20 by jgo               #+#    #+#              #
#    Updated: 2022/11/17 11:02:01 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

# VARIABLE DECLEARATION

CFLAGS =  -Wall -Wextra -Werror -MMD -MP
CPPFLAGS = -I./includes -I./libft/includes
LDFLAGS = -L./libft
LDLIBS = -lft
ARFLAGS = rcs

DEQUEUE = dequeue
UTILS = utils
COMMANDS = commands
PUSHSWAP = push_swap
CHECKER = checker

OBJS_DIR = objs
INCLUDE_DIR = ./includes
MANDATORY_DIR = mandatory
BONUS_DIR = bonus

LIB_MANDATORY_DIR = libft_mandatory
LIB_BONUS_DIR = libft_bonus

GNL_DIR = get_next_line
PRINTF_DIR = ft_printf
PRINTF_LIB_DIR = libft_printf
PUSHSWAP_LIB_DIR = libft_pushswap

# verbose
Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

# debug
ifdef DEBUG
        CFLAGS += -fsanitize=address -g3
endif
