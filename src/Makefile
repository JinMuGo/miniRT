# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:42:33 by jgo               #+#    #+#              #
#    Updated: 2023/07/16 18:46:07 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ../)
endif

include $(TOPDIR)/make_config/src/Rules.mk
include $(TOPDIR)/make_config/com/Color.mk
include $(TOPDIR)/make_config/com/Funcs.mk
include $(TOPDIR)/make_config/com/Flags.mk

all : 
	$(MAKE) TOPDIR=$(TOPDIR) -C $(MANDATORY_DIR) $@

bonus :
	$(MAKE) TOPDIR=$(TOPDIR) -C $(BONUS_DIR) $@

clean fclean :
	$(MAKE) TOPDIR=$(TOPDIR) -C $(MANDATORY_DIR) $@
	$(MAKE) TOPDIR=$(TOPDIR) -C $(BONUS_DIR) $@

re : fclean
	$(MAKE) TOPDIR=$(TOPDIR) -C $(MANDATORY_DIR)

.PHONY: all clean fclean re bonus
