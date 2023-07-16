# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 14:05:59 by jgo               #+#    #+#              #
#    Updated: 2023/07/16 18:47:54 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR	:= $(abspath ../../)
endif

include		$(TOPDIR)/make_config/src/Rules.mk
include		$(TOPDIR)/make_config/com/Funcs.mk
include		$(TOPDIR)/make_config/com/Flags.mk
include 	$(TOPDIR)/make_config/com/Color.mk

NAME	:=	$(BONUS_NAME)

DIRS	:=	design_patterns_bonus \
			scene_bonus \
			utils_bonus \
			parser_bonus \
			render_bonus \
			light_bonus \
			hooks_bonus

LIBS	:=	$(addsuffix .a, $(addprefix lib/, $(DIRS)))

HEADS	:=	prt_color_bonus.h \
			const_bonus.h \
			defs_bonus.h \
			design_patterns_bonus.h \
			enum_bonus.h \
			minirt_bonus.h \
			struct_bonus.h \
			utils_bonus.h \
			parser_bonus.h \
			hooks_bonus.h \
			thread_bonus.h

SRCS	:=	main_bonus.c

OBJS	:=	$(SRCS:.c=.o)
DEPS 	:=	$(SRCS:.c=.d)

-include	$(DEPS)
include		$(TOPDIR)/make_config/src/BonusRecipes.mk
