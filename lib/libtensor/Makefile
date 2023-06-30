# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 12:56:36 by jgo               #+#    #+#              #
#    Updated: 2023/06/26 14:58:05 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ../../)
endif
include $(TOPDIR)/make_config/com/ColorRules.mk
include $(TOPDIR)/make_config/lib/Rules.mk

NAME := libtensor.a

HEAD := tensor.h

DIRS := libvector \
		libangle \
		libequation \
		libmatrix

LIBS := $(addsuffix .a, $(addprefix libs/, $(DIRS)))
-include $(DEPS)

include $(TOPDIR)/make_config/lib/Recipes.mk
