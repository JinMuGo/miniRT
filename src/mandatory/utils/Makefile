# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 08:31:25 by jgo               #+#    #+#              #
#    Updated: 2023/06/07 19:13:26 by sanghwal         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ../../../)
endif

include $(TOPDIR)/make_config/com/ColorRules.mk
include $(TOPDIR)/make_config/src/Rules.mk

SRCS :=	destroy.c \
		hooks.c \
		rgb.c \
		atod.c

NAME := utils.a

OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
-include $(DEPS)

include $(TOPDIR)/make_config/src/SubLibsRecipes.mk
