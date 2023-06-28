# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 14:05:59 by jgo               #+#    #+#              #
#    Updated: 2023/06/20 15:07:05 by sanghwal         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR	:= $(abspath ../../)
endif

include		$(TOPDIR)/make_config/src/Rules.mk
include 	$(TOPDIR)/make_config/com/ColorRules.mk

NAME	:=	$(BONUS_NAME)

DIRS	:=	design_patterns \
			scene \
			utils \
			parser \
			render \
			light \
			hooks

LIBS	:=	$(addsuffix .a, $(addprefix lib/, $(DIRS)))

HEADS	:=	prt_color.h \
			const.h \
			defs.h \
			design_patterns.h \
			enum.h \
			minirt.h \
			struct.h \
			utils.h \
			parser.h \
			hooks.h \
			thread.h

SRCS	:=	main.c

OBJS	:=	$(SRCS:.c=.o)
DEPS 	:=	$(SRCS:.c=.d)

-include	$(DEPS)
include		$(TOPDIR)/make_config/src/BonusRecipes.mk
