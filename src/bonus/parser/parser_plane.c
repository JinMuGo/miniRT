/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:51:52 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/22 16:17:00 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	vaildation_plane(t_plane *plane)
{
	if (plane->type != PL)
		return (false);
	if (!check_normal_vec(plane->normal_vec3) || !check_rgba(plane->rgba))
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

void	parser_plane(char **line)
{
	const int		len = ft_arrlen((void **)line);
	t_obj_option	*option;
	t_meta			*meta;
	t_plane			plane;
	t_obj			*obj;

	if (!(len == 4 || len == 9))
		error_handler(PL_ERR);
	plane.type = PL;
	plane.point = parser_point3(line[1]);
	plane.normal_vec3 = vec3_unit(parser_vec3(line[2]));
	plane.rgba = parser_rgba(line[3]);
	if (line[4])
		option = _option_allocator(line);
	else
		option = NULL;
	if (!vaildation_plane(&plane) || !vaildation_option(option))
	{
		ft_free_all_arr(line);
		error_handler(PL_ERR);
	}
	meta = singleton();
	obj = ft_malloc(sizeof(t_obj));
	obj->type = PL;
	obj->content.plane = plane;
	obj->option = option;
	obj->next = NULL;
	objsadd_back(&meta->objs, obj);
}
