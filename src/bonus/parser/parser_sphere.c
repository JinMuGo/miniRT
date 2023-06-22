/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:00:17 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/22 16:17:17 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	vaildation_sphere(t_sphere *sphere)
{
	if (sphere->type != SP)
		return (false);
	if (!check_rgba(sphere->rgba) || sphere->diameter <= 0)
		return (false);
	return (true);
}

static inline t_obj_option *_cb_allocator(char **line)
{
	t_obj_option *option;

	option = ft_malloc(sizeof(t_obj_option));
	option->type = CB;
	option->op.cb.rgba = parser_rgba(line[5]);
	option->op.cb.scale_s = check_to_double(line[6]);
	option->op.cb.scale_t = check_to_double(line[7]);
	option->op.cb.degree = check_to_double(line[8]);
	return (option);
}

static inline t_obj_option	*_option_allocator(char **line)
{
	if (!ft_strcmp(line[4], "cb"))
		return (_cb_allocator(line));
	else
		return (NULL);
	// else if (!ft_strcmp(line[4], "bp"))
	// 	sphere->option = _bp_allocator(line);
}

void	parser_sphere(char **line)
{
	const int		len = ft_arrlen((void **)line);
	t_obj_option	*option;
	t_meta			*meta;
	t_obj			*obj;
	t_sphere		sphere;

	if (!(len == 4 || len == 9))
		error_handler(SP_ERR);
	sphere.type = SP;
	sphere.center_point = parser_point3(line[1]);
	sphere.diameter = check_to_double(line[2]);
	sphere.radius = sphere.diameter / 2;
	sphere.rgba = parser_rgba(line[3]);
	if (line[4])
		option = _option_allocator(line);
	else
		option = NULL;
	if (!vaildation_sphere(&sphere) || !vaildation_option(option))
	{
		ft_free_all_arr(line);
		error_handler(SP_ERR);
	}
	meta = singleton();
	obj = ft_malloc(sizeof(t_obj));
	obj->type = SP;
	obj->content.sphere = sphere;
	obj->option = option;
	obj->next = NULL;
	objsadd_back(&meta->objs, obj);
}
