/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:50:54 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/22 16:16:38 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	vaildation_cylinder(t_cylinder *cylinder)
{
	if (cylinder->type != CY)
		return (false);
	if (!check_normal_vec(cylinder->normal_vec3)
		|| !check_rgba(cylinder->rgba)
		|| cylinder->diameter <= 0
		|| cylinder->height <= 0)
		return (false);
	return (true);
}

static inline t_obj_option *_cb_allocator(char **line)
{
	t_obj_option *option;

	option = ft_malloc(sizeof(t_obj_option));
	option->type = CB;
	option->op.cb.rgba = parser_rgba(line[7]);
	option->op.cb.scale_s = check_to_double(line[8]);
	option->op.cb.scale_t = check_to_double(line[9]);
	option->op.cb.degree = check_to_double(line[10]);
	return (option);
}

static inline t_obj_option	*_option_allocator(char **line)
{
	if (!ft_strcmp(line[6], "cb"))
		return (_cb_allocator(line));
	else
		return (NULL);
	// else if (!ft_strcmp(line[4], "bp"))
	// 	cylindeer->option = _bp_allocator(line);
}

void	parser_cylinder(char **line)
{
	const int		len = ft_arrlen((void **)line);
	t_obj_option	*option;
	t_cylinder		cylinder;
	t_meta			*meta;
	t_obj			*obj;

	if (!(len == 6 || len == 11))
		error_handler(CY_ERR);
	cylinder.type = CY;
	cylinder.center_point = parser_point3(line[1]);
	cylinder.normal_vec3 = vec3_unit(parser_vec3(line[2]));
	cylinder.diameter = check_to_double(line[3]);
	cylinder.height = check_to_double(line[4]);
	cylinder.rgba = parser_rgba(line[5]);
	if (line[6])
		option = _option_allocator(line);
	else
		option = NULL;
	if (!vaildation_cylinder(&cylinder) || !vaildation_option(option))
	{
		ft_free_all_arr(line);
		error_handler(CY_ERR);
	}
	meta = singleton();
	obj = ft_malloc(sizeof(t_obj));
	obj->type = CY;
	obj->content.cylinder = cylinder;
	obj->option = option;
	obj->next = NULL;
	objsadd_back(&meta->objs, obj);
}
