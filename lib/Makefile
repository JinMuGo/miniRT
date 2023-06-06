# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:42:33 by jgo               #+#    #+#              #
#    Updated: 2023/06/06 17:43:33 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ..)
endif

include $(TOPDIR)/make_config/com/ColorRules.mk
include $(TOPDIR)/make_config/lib/Rules.mk

LIBS := libft

$(LIBS):
	$(MAKE) -C $@

all bonus:
	$(Q)$(call color_printf,$(YELLOW),$(PROJECT_NAME),🎯 Start compiling)
	$(MAKE) $(LIBS)
	$(Q)$(call color_printf,$(GREEN),$(PROJECT_NAME),✨ compiled!)

fclean clean re:
	$(Q)$(foreach dir, $(LIBS), $(MAKE) -C $(dir) $@;)

.PHONY: all clean fclean re bonus $(LIBS)
