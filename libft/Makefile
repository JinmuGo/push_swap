# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 12:56:36 by jgo               #+#    #+#              #
#    Updated: 2022/11/15 15:56:38 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

ifndef ROOT_DIR 
        ROOT_DIR = $(abspath ..)
endif

include $(ROOT_DIR)/config/var_def.mk
include $(ROOT_DIR)/config/compile_rules.mk
include $(ROOT_DIR)/config/color_rules.mk

NAME = libft.a

SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putstr_fd.c \
	ft_putnbr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c 
	
BONUS = ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c 

GNL = get_next_line_bonus.c \
	get_next_line_utils_bonus.c

PRINTF = ft_printf.c \
		 ft_printf_c.c \
		 ft_printf_d.c \
		 ft_printf_p.c \
		 ft_printf_s.c \
		 ft_printf_u.c \
		 ft_printf_x.c

PRINTF_LIB = ft_itoa_base.c \
			ft_putchar.c \
			ft_printf_strchr.c \
			ft_putstr.c \

PUSHSWAP_LIB = ft_isspace.c \
			ft_free_all_arr.c \
			ft_isinteger.c


OBJS = $(addprefix $(OBJS_DIR)/$(LIB_MANDATORY_DIR)/, $(SRCS:.c=.o))
GNL_OBJS = $(addprefix $(OBJS_DIR)/$(GNL_DIR)/, $(GNL:.c=.o))
BONUS_OBJS = $(addprefix $(OBJS_DIR)/$(LIB_BONUS_DIR)/, $(BONUS:.c=.o))
PRINTF_OBJS = $(addprefix $(OBJS_DIR)/$(PRINTF_DIR)/, $(PRINTF:.c=.o))
PRINTF_LIB_OBJS = $(addprefix $(OBJS_DIR)/$(PRINTF_LIB_DIR)/, $(PRINTF_LIB:.c=.o))
PUSHSWAP_LIB_OBJS = $(addprefix $(OBJS_DIR)/$(PUSHSWAP_LIB_DIR)/, $(PUSHSWAP_LIB:.c=.o))

all bonus: $(NAME)

$(NAME): $(OBJS) $(BONUS_OBJS) $(GNL_OBJS) $(PRINTF_OBJS) $(PUSHSWAP_LIB_OBJS) $(PRINTF_LIB_OBJS)
	$(Q)$(AR) $(ARFLAGS) $@ $^
	$(call color_printf,libft,$(KGRN),generated libft.a,$(KNRM))

clean:
	$(Q)$(RM) -r $(OBJS_DIR)
	$(call color_printf,objs,$(KRED),removed libft objs directory,$(KNRM))

fclean: clean
	$(Q)$(RM) $(NAME)
	$(call color_printf,libft,$(KRED),removed libft.a,$(KNRM))

re:
	$(Q)$(MAKE) fclean
	$(Q)$(MAKE) all

.PHONY: all bonus clean fclean re
