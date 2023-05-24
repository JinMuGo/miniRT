# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 19:51:48 by jgo               #+#    #+#              #
#    Updated: 2023/05/24 19:57:22 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ../../)
endif
include $(TOPDIR)/make_config/Rules.mk
include $(TOPDIR)/make_config/ColorRules.mk

NOM		=	libmlx.a
SRC		=	mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC		+=	mlx_png.c mlx_mouse.m
OBJ1	=	$(SRC:.c=.o)
OBJ		=	$(OBJ1:.m=.o)
CFLAGS	+=	-O2 -w

# add to match string put with X11 in size and position
CFLAGS +=	-DSTRINGPUTX11

HEAD	:=	mlx_int.h \
			mlx_new_window.h \
			mlx_opengl.h \
			mlx_png.h \
			mlx.h

all:
	$(MAKE) $(NOM)
	$(Q)$(MAKE) files="$(NOM)" src_dir=`pwd` dst_dir=$(TOPDIR)/lib link_files
	$(Q)$(MAKE) files="$(HEAD)" src_dir=`pwd` dst_dir=$(TOPDIR)/includes link_files

$(NOM):: $(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)

clean:
	$(Q)$(MAKE) files="$(NOM)" src_dir=`pwd` dst_dir=$(TOPDIR)/lib unlink_files
	$(Q)$(MAKE) files="$(HEAD)" src_dir=`pwd` dst_dir=$(TOPDIR)/includes unlink_files
	rm -f $(OBJ) *~

fclean: clean
	rm -f $(NOM) 

re: clean all
