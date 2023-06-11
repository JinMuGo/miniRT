/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:00:02 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/11 16:10:25 by sanghwal         ###   ########seoul.kr  */
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

	if (!*objs || !del)
		return ;
	while (*objs)
	{
		obj = (*objs)->next;
		free(obj);
		*objs = obj;
	}
	*objs = NULL;
}
