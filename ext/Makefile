# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:42:33 by jgo               #+#    #+#              #
#    Updated: 2023/06/06 18:57:51 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ..)
endif

include $(TOPDIR)/make_config/com/ColorRules.mk
include $(TOPDIR)/make_config/ext/Rules.mk

HEADS :=	MLX42.h

build_mlx :
	cmake $(PROJECT_NAME) -B build

compile_mlx : build_mlx
	$(MAKE) -C build -j8

all bonus:
	$(Q)$(call color_printf,$(YELLOW),$(PROJECT_NAME),🎯 Start compiling)
	$(Q)$(MAKE) files="$(HEADS)" src_dir=`pwd`/$(PROJECT_NAME)/include/$(PROJECT_NAME) dst_dir=$(TOPDIR)/includes link_files
	$(MAKE) compile_mlx
	$(Q)$(MAKE) files="$(ARCHIVE_NAME)" src_dir=`pwd`/build dst_dir=$(TOPDIR)/ext link_files
	$(Q)$(call color_printf,$(GREEN),$(PROJECT_NAME),✨ compiled!)

fclean clean:
	$(Q)$(call color_printf,$(RED),$(PROJECT_NAME),🗑️  remove Objects && Dependency file)
	$(Q)$(MAKE) files="$(HEADS)" src_dir=`pwd`/$(PROJECT_NAME)/include$(PROJECT_NAME) dst_dir=$(TOPDIR)/includes unlink_files
	$(Q)$(MAKE) files="$(ARCHIVE_NAME)" src_dir=`pwd`/build dst_dir=$(TOPDIR)/ext unlink_files
	$(RM) build

re : fclean
	$(MAKE) all


.PHONY: all clean fclean re bonus $(LIBS)
