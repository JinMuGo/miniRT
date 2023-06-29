/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:50:54 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 15:36:53 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	_vaildation_cylinder(t_cylinder *cylinder)
{
	if (cylinder->type != CY
		|| !check_normal_vec(cylinder->normal_vec3)
		|| !check_rgba(cylinder->rgba)
		|| cylinder->diameter <= 0
		|| cylinder->height <= 0)
		return (false);
	return (true);
}

static inline void	_set_cylinder_info(t_cylinder *cylinder, char **line)
{
	cylinder->type = CY;
	cylinder->center_point = parser_point3(line[1]);
	cylinder->normal_vec3 = vec3_unit(parser_vec3(line[2]));
	cylinder->diameter = check_to_double(line[3]);
	cylinder->height = check_to_double(line[4]);
	cylinder->rgba = parser_rgba(line[5]);
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
	obj->next = NULL;
	objsadd_back(&singleton()->objs, obj);
}
