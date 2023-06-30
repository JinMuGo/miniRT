/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:51:52 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/30 10:45:52 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "render.h"
#include "design_patterns.h"

static bool	_vaildation_plane(t_plane *plane)
{
	if (plane->type != PL)
		return (false);
	if (!check_normal_vec(plane->normal_vec3) || !check_rgb(&plane->rgb))
		return (false);
	return (true);
}

static inline void	_set_plane_info(t_plane *plane, char **line)
{
	plane->type = PL;
	plane->point = parser_vec3(line[1], POINT_ERR);
	plane->normal_vec3 = vec3_unit(parser_vec3(line[2], VEC_ERR));
	plane->rgb = parser_vec3(line[3], RGB_ERR);
}

void	parser_plane(char **line)
{
	t_meta	*meta;
	t_plane	plane;
	t_obj	*obj;

	if (ft_arrlen((void **)line) != 4)
		error_handler(PL_ERR);
	_set_plane_info(&plane, line);
	if (!_vaildation_plane(&plane))
	{
		ft_free_all_arr(line);
		error_handler(PL_ERR);
	}
	meta = singleton();
	obj = ft_malloc(sizeof(t_obj));
	obj->type = PL;
	obj->content.plane = plane;
	obj->get_t = get_plane_dist;
	obj->set_r = set_plane_record;
	obj->next = NULL;
	objsadd_back(&meta->objs, obj);
}
