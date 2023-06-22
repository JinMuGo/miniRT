/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:00:02 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/22 15:20:05 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "parser.h"

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

void	objs_clear(t_obj **objs, void (*del)(void *))
{
	t_obj	*obj;
	t_obj_option *option;

	if (!*objs || !del)
		return ;
	while (*objs)
	{
		obj = (*objs)->next;
		option = (*objs)->option;
		if (option)
			del(option);
		del(*objs);
		*objs = obj;
	}
	*objs = NULL;
}
