# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 14:05:59 by jgo               #+#    #+#              #
#    Updated: 2023/06/06 14:35:11 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ../../)
endif

include $(TOPDIR)/make_config/src/Rules.mk
include $(TOPDIR)/make_config/com/ColorRules.mk

NAME = $(join $(BONUS_NAME), _bonus)

DIRS = commands_bonus dequeue_bonus utils_bonus
LIBS = $(addsuffix .a, $(addprefix lib/, $(DIRS)))

HEADS =	push_swap_bonus.h

SRCS = main_bonus.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

include $(TOPDIR)/make_config/src/Recipes.mk
