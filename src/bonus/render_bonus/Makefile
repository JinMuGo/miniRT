# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 14:55:11 by sanghwal          #+#    #+#              #
#    Updated: 2023/07/16 18:46:07 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ../../../)
endif

include $(TOPDIR)/make_config/com/Color.mk
include $(TOPDIR)/make_config/com/Funcs.mk
include $(TOPDIR)/make_config/com/Flags.mk
include $(TOPDIR)/make_config/src/Rules.mk

SRCS :=	ray_bonus.c \
		render_bonus.c \
		apply_option_bonus.c \
		thread_bonus.c \
		find_obj_bonus.c \
		render_plane_bonus.c \
		render_sphere_bonus.c \
		render_cylinder_bonus.c \
		render_cylinder2_bonus.c \
		set_cylinder_uv_bonus.c \
		render_cone_bonus.c \
		render_cone2_bonus.c

NAME := render_bonus.a

OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
-include $(DEPS)

include $(TOPDIR)/make_config/src/BonusSubLibsRecipes.mk
