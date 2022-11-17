# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile_rules.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 20:10:27 by jgo               #+#    #+#              #
#    Updated: 2022/11/17 11:01:00 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# push_swap
DEQUEUE_OBJS = $(addprefix $(OBJS_DIR)/$(DEQUEUE)/, $(DEQUEUE_SRCS:.c=.o))
DEQUEUE_DEPS = $(addprefix $(OBJS_DIR)/$(DEQUEUE)/, $(DEQUEUE_SRCS:.c=.d))
-include $(addprefix $(OBJS_DIR)/$(DEQUEUE)/, $(PUSHSWAP_DEPS))

UTILS_OBJS = $(addprefix $(OBJS_DIR)/$(UTILS)/, $(UTILS_SRCS:.c=.o))
UTILS_DEPS = $(addprefix $(OBJS_DIR)/$(UTILS)/, $(UTILS_SRCS:.c=.d))
-include $(addprefix $(OBJS_DIR)/$(UTILS)/, $(UTILS_DEPS))

COMMANDS_OBJS = $(addprefix $(OBJS_DIR)/$(COMMANDS)/, $(COMMANDS_SRCS:.c=.o))
COMMANDS_DEPS = $(addprefix $(OBJS_DIR)/$(COMMANDS)/, $(COMMANDS_SRCS:.c=.d))
-include $(addprefix $(OBJS_DIR)/$(COMMANDS)/, $(COMMANDS_DEPS))

PUSHSWAP_OBJS = $(addprefix $(OBJS_DIR)/$(MANDATORY_DIR)/, $(PUSHSWAP_SRCS:.c=.o))
PUSHSWAP_DEPS = $(addprefix $(OBJS_DIR)/$(MANDATORY_DIR)/, $(PUSHSWAP_SRCS:.c=.d))
-include $(addprefix $(OBJS_DIR)/$(MANDATORY_DIR)/, $(PUSHSWAP_DEPS))

# checker
CHECKER_OBJS = $(addprefix $(OBJS_DIR)/$(BONUS_DIR)/, $(CHECKER_SRCS:.c=.o))
CHECKER_DEPS = $(addprefix $(OBJS_DIR)/$(BONUS_DIR)/, $(CHECKER_SRCS:.c=.d))
-include $(addprefix $(OBJS_DIR)/$(BONUS_DIR)/, $(CHECKER_DEPS))

# MANDATORY 
$(OBJS_DIR)/$(MANDATORY_DIR)/%.o : $(MANDATORY_DIR)/%.c
	$(Q)mkdir -p $(OBJS_DIR)
	$(Q)mkdir -p $(OBJS_DIR)/$(MANDATORY_DIR)
	$(Q)$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -I $(INCLUDE_DIR) -o $@

# BONUS
$(OBJS_DIR)/$(BONUS_DIR)/%.o : $(BONUS_DIR)/%.c
	$(Q)mkdir -p $(OBJS_DIR)
	$(Q)mkdir -p $(OBJS_DIR)/$(BONUS_DIR)
	$(Q)$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -I $(INCLUDE_DIR) -o $@

# DEQUEUE
$(OBJS_DIR)/$(DEQUEUE)/%.o : $(DEQUEUE)/%.c
	$(Q)mkdir -p $(OBJS_DIR)
	$(Q)mkdir -p $(OBJS_DIR)/$(DEQUEUE)
	$(Q)$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -I $(INCLUDE_DIR) -o $@

# UTILS
$(OBJS_DIR)/$(UTILS)/%.o : $(UTILS)/%.c
	$(Q)mkdir -p $(OBJS_DIR)
	$(Q)mkdir -p $(OBJS_DIR)/$(UTILS)
	$(Q)$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -I $(INCLUDE_DIR) -o $@

# COMMAND
$(OBJS_DIR)/$(COMMANDS)/%.o : $(COMMANDS)/%.c
	$(Q)mkdir -p $(OBJS_DIR)
	$(Q)mkdir -p $(OBJS_DIR)/$(COMMANDS)
	$(Q)$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -I $(INCLUDE_DIR) -o $@

#  libft.a
$(OBJS_DIR)/$(LIB_MANDATORY_DIR)/%.o : $(LIB_MANDATORY_DIR)/%.c
	$(Q)mkdir -p $(OBJS_DIR)
	$(Q)mkdir -p $(OBJS_DIR)/$(LIB_MANDATORY_DIR)
	$(Q)$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -I $(INCLUDE_DIR) -o $@
	
$(OBJS_DIR)/$(LIB_BONUS_DIR)/%.o : $(LIB_BONUS_DIR)/%.c
	$(Q)mkdir -p $(OBJS_DIR)
	$(Q)mkdir -p $(OBJS_DIR)/$(LIB_BONUS_DIR)
	$(Q)$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -I $(INCLUDE_DIR) -o $@

$(OBJS_DIR)/$(GNL_DIR)/%.o : $(GNL_DIR)/%.c
	$(Q)mkdir -p $(OBJS_DIR)
	$(Q)mkdir -p $(OBJS_DIR)/$(GNL_DIR)
	$(Q)$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -I $(INCLUDE_DIR) -o $@

$(OBJS_DIR)/$(PRINTF_DIR)/%.o : $(PRINTF_DIR)/%.c
	$(Q)mkdir -p $(OBJS_DIR)
	$(Q)mkdir -p $(OBJS_DIR)/$(PRINTF_DIR)
	$(Q)$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -I $(INCLUDE_DIR) -o $@

$(OBJS_DIR)/$(PRINTF_LIB_DIR)/%.o : $(PRINTF_LIB_DIR)/%.c
	$(Q)mkdir -p $(OBJS_DIR)
	$(Q)mkdir -p $(OBJS_DIR)/$(PRINTF_LIB_DIR)
	$(Q)$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -I $(INCLUDE_DIR) -o $@

$(OBJS_DIR)/$(PUSHSWAP_LIB_DIR)/%.o : $(PUSHSWAP_LIB_DIR)/%.c
	$(Q)mkdir -p $(OBJS_DIR)
	$(Q)mkdir -p $(OBJS_DIR)/$(PUSHSWAP_LIB_DIR)
	$(Q)$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -I $(INCLUDE_DIR) -o $@