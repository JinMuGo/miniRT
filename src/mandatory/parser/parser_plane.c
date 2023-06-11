/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:51:52 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/11 16:12:18 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	vaildation_plane(t_plane *plane)
{
	if (plane->type != PL)
		return (false);
	if (!check_minus1_to_1(plane->normal_vec3.x)
		|| !check_minus1_to_1(plane->normal_vec3.y)
		|| !check_minus1_to_1(plane->normal_vec3.z)
		|| !check_rgba(plane->rgba))
		return (false);
	return (true);
}

void	parser_plane(char **line)
{
	t_meta	*meta;
	t_plane	plane;
	t_obj	*obj;

	if (ft_arrlen((void **)line) != 4)
		parser_error("Incorrect number of plane information\n");
	plane.type = PL;
	plane.point = parser_point3(line[1]);
	plane.normal_vec3 = parser_vec3(line[2]);
	plane.rgba = parser_rgba(line[3]);
	if (!vaildation_plane(&plane))
	{
		ft_free_all_arr(line);
		parser_error("Invaild sphere\n");
	}
	meta = singleton();
	obj = ft_malloc(sizeof(t_obj));
	obj->type = PL;
	obj->content.plane = plane;
	obj->next = NULL;
	objsadd_back(&meta->objs, obj);
}
