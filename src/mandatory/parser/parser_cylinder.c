/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:50:54 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/30 10:46:31 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "render.h"
#include "design_patterns.h"

static bool	_vaildation_cylinder(t_cylinder *cylinder)
{
	if (cylinder->type != CY
		|| !check_normal_vec(cylinder->normal_vec3)
		|| !check_rgb(&cylinder->rgb)
		|| cylinder->diameter <= 0
		|| cylinder->height <= 0)
		return (false);
	return (true);
}

static inline void	_set_cylinder_info(t_cylinder *cylinder, char **line)
{
	cylinder->type = CY;
	cylinder->center_point = parser_vec3(line[1], POINT_ERR);
	cylinder->normal_vec3 = vec3_unit(parser_vec3(line[2], VEC_ERR));
	cylinder->diameter = check_to_double(line[3]);
	cylinder->height = check_to_double(line[4]);
	cylinder->rgb = parser_vec3(line[5], RGB_ERR);
}

void	parser_cylinder(char **line)
{
	const int		len = ft_arrlen((void **)line);
	t_cylinder		cylinder;
	t_obj			*obj;

	if (!(len == 6))
		error_handler(CY_ERR);
	_set_cylinder_info(&cylinder, line);
	if (!_vaildation_cylinder(&cylinder))
	{
		ft_free_all_arr(line);
		error_handler(CY_ERR);
	}
	obj = ft_malloc(sizeof(t_obj));
	obj->type = CY;
	obj->content.cylinder = cylinder;
	obj->get_t = get_cylinder_dist;
	obj->set_r = set_cylinder_record;
	obj->next = NULL;
	objsadd_back(&singleton()->objs, obj);
}
