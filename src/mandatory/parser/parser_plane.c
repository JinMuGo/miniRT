/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:51:52 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/10 11:07:28 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "render.h"
#include "utils.h"
#include "design_patterns.h"

static bool	_vaildation_plane(t_plane *plane)
{
	if (plane->type != PL)
		return (false);
	if (!check_normal_vec(plane->normal_vec3) || !check_rgb(&plane->rgb)
		|| fabs(1 - vec3_length(plane->normal_vec3)) > EPSILON)
		return (false);
	return (true);
}

static inline void	_set_plane_info(t_plane *plane, char **line)
{
	plane->type = PL;
	plane->point = parser_vec3(line[1], POINT_ERR);
	plane->normal_vec3 = parser_vec3(line[2], VEC_ERR);
	plane->rgb = parser_vec3(line[3], RGB_ERR);
}

static inline t_obj	*_set_obj_info(t_plane plane)
{
	t_obj	*obj;

	obj = ft_malloc(sizeof(t_obj));
	obj->type = PL;
	obj->content.plane = plane;
	obj->get_t = get_plane_dist;
	obj->set_r = set_plane_record;
	obj->next = NULL;
	return (obj);
}

void	parser_plane(char **line)
{
	t_plane	plane;

	if (ft_arrlen((void **)line) != 4)
		error_handler(PL_ERR);
	_set_plane_info(&plane, line);
	if (!_vaildation_plane(&plane))
	{
		ft_free_all_arr(line);
		error_handler(PL_ERR);
	}
	objsadd_back(&singleton()->objs, _set_obj_info(plane));
}
