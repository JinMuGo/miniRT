# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 14:05:59 by jgo               #+#    #+#              #
#    Updated: 2023/06/07 17:04:12 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR	:= $(abspath ../../)
endif

include		$(TOPDIR)/make_config/src/Rules.mk
include 	$(TOPDIR)/make_config/com/ColorRules.mk

NAME	:=	$(PROJECT_NAME)

DIRS	:=	design_patterns \
			utils

LIBS	:=	$(addsuffix .a, $(addprefix lib/, $(DIRS)))

HEADS	:=	color.h \
			const.h \
			defs.h \
			design_patterns.h \
			enum.h \
			minirt.h \
			struct.h \
			utils.h

SRCS	:=	main.c

OBJS	:=	$(SRCS:.c=.o)
DEPS 	:=	$(SRCS:.c=.d)

-include	$(DEPS)
include		$(TOPDIR)/make_config/src/Recipes.mk
