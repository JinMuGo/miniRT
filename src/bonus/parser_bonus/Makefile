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

SRCS :=	parser_bonus.c \
		ft_split_whitespace_bonus.c \
		option_allocator_bonus.c \
		parser_ambient_bonus.c \
		parser_camera_bonus.c \
		parser_lights_bonus.c \
		parser_sphere_bonus.c \
		parser_plane_bonus.c \
		parser_cylinder_bonus.c \
		parser_cone_bonus.c \
		parser_point_vec_bonus.c \
		parser_atod_bonus.c \
		parser_utils_bonus.c \
		parser_utils2_bonus.c \
		parser_print_bonus.c \
		parser_print_objs_bonus.c \

NAME := parser_bonus.a

OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
-include $(DEPS)

include $(TOPDIR)/make_config/src/BonusSubLibsRecipes.mk
