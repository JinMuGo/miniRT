# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 14:55:11 by sanghwal          #+#    #+#              #
#    Updated: 2023/06/18 17:42:21 by sanghwal         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ../../../)
endif

include $(TOPDIR)/make_config/com/ColorRules.mk
include $(TOPDIR)/make_config/src/Rules.mk

SRCS :=	parser.c \
		ft_split_whitespace.c \
		parser_ambient.c \
		parser_camera.c \
		parser_lights.c \
		parser_sphere.c \
		parser_plane.c \
		parser_cylinder.c \
		parser_point_vec.c \
		parser_atod.c \
		parser_rgba.c \
		parser_utils.c \
		parser_utils2.c \
		parser_print.c \
		parser_print_objs.c

NAME := parser.a

OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
-include $(DEPS)

include $(TOPDIR)/make_config/src/SubLibsRecipes.mk