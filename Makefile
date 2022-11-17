# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 20:10:46 by jgo               #+#    #+#              #
#    Updated: 2022/11/17 11:00:50 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./config/var_def.mk
include ./config/color_rules.mk

##################################################################
# sub_src compile
LIBFT = libft/libft.a
$(LIBFT):
	$(Q)$(MAKE) -C $(@D)

DEQUEUE_SRCS = deque.c \
			enque.c

UTILS_SRCS = error.c \
			input.c \
			utils.c

PUSHSWAP_SRCS = push_swap.c \
				less_than_five.c \
				sort.c \
				utils.c \
				rotate_stack_ab.c \
				a_to_right_place.c \
				b_to_a.c \
				align_stack_a.c

CHECKER_SRCS = checker_bonus.c \
			deque_bonus.c \
			enque_bonus.c \
			command_bonus.c  \
			input_bonus.c \
			utils_bonus.c

COMMANDS_SRCS = commands.c \
				cmd_compare.c

include ./config/compile_rules.mk

$(PUSHSWAP): $(PUSHSWAP_OBJS) $(DEQUEUE_OBJS) $(UTILS_OBJS) $(COMMANDS_OBJS)
	$(Q)$(CC) $(CFLAGS) $(CPPFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
$(PUSHSWAP_OBJS): $(LIBFT)

$(CHECKER):$(CHECKER_OBJS)
	$(Q)$(CC) $(CFLAGS) $(CPPFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
$(CHECKER_OBJS): $(LIBFT) 

all: $(PUSHSWAP_OBJS)
	$(MAKE) $(PUSHSWAP)

bonus: $(CHECKER_OBJS)
	$(MAKE) $(CHECKER)

clean:
	$(Q)$(MAKE) -C $(dir $(LIBFT)) clean
	$(Q)$(RM) -r $(OBJS_DIR)
	$(call color_printf,objs,$(KRED),removed root objs directory,$(KNRM))

fclean: clean
	$(Q)$(RM) $(LIBFT) $(PUSHSWAP) $(CHECKER)
	$(call color_printf,proj,$(KRED),removed libft push_swap checker,$(KNRMk))

re: fclean
	$(Q)$(MAKE) all

.PHONY: all clean fclean re bonus