/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:00:02 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/03 17:44:43 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "defs_bonus.h"
#include "parser_bonus.h"

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
		if (option->op.tx.bp)
			del(option->op.tx.bp);
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
