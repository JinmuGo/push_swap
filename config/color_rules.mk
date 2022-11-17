# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    color_rules.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 20:12:51 by jgo               #+#    #+#              #
#    Updated: 2022/11/17 11:02:57 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# it's pretty right?
KNRM = \x1B[0m
KRED = \x1B[31m
KGRN = \x1B[32m
KYEL = \x1B[33m
KBLU = \x1B[34m
KMAG = \x1B[35m
KCYN = \x1B[36m
KWHT = \x1B[37m

## printf function define
define color_printf
    @printf "%b\n" "$(2)[$(1)] $(4)$(3)"
endef