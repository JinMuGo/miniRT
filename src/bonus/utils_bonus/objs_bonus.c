/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:00:02 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/13 22:40:10 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "defs_bonus.h"
#include "parser_bonus.h"
#include "design_patterns_bonus.h"

void	objsadd_back(t_obj **objs, t_obj *new)
{
	t_obj	*node;

	if (!new)
		return ;
	if (!*objs)
	{
		*objs = new;
		return ;
	}
	node = *objs;
	while (node->next)
		node = node->next;
	node->next = new;
}

static inline void	_option_clear(t_obj_option *option, void (*del)(void *))
{
	if (option->type == TX)
	{
		mlx_destroy_image(singleton()->mlx_assets.mlx, option->op.tx.img.texture->img.img);
		del(option->op.tx.img.texture);
		if (option->op.tx.bp)
		{
			mlx_destroy_image(singleton()->mlx_assets.mlx, option->op.tx.bp->texture->img.img);
			del(option->op.tx.bp->texture);
			del(option->op.tx.bp);
		}
	}
	del(option);
}

void	objs_clear(t_obj **objs, void (*del)(void *))
{
	t_obj			*obj;
	t_obj_option	*option;

	if (!*objs || !del)
		return ;
	while (*objs)
	{
		obj = (*objs)->next;
		option = (*objs)->option;
		if (option)
			_option_clear((*objs)->option, del);
		del(*objs);
		*objs = obj;
	}
	*objs = NULL;
}
