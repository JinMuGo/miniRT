/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:50:54 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/16 18:16:45 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	vaildation_cylinder(t_cylinder *cylinder)
{
	if (cylinder->type != CY)
		return (false);
	if (!check_normal_vec(cylinder->normal_vec3) || !check_rgba(cylinder->rgba))
		return (false);
	return (true);
}

void	parser_cylinder(char **line)
{
	t_meta		*meta;
	t_cylinder	cylinder;
	t_obj		*obj;

	if (ft_arrlen((void **)line) != 6)
		parser_error("Incorrect number of cylinder information\n");
	cylinder.type = CY;
	cylinder.center_point = parser_point3(line[1]);
	cylinder.normal_vec3 = vec3_unit(parser_vec3(line[2]));
	cylinder.diameter = check_to_double(line[3]);
	cylinder.height = check_to_double(line[4]);
	cylinder.rgba = parser_rgba(line[5]);
	if (!vaildation_cylinder(&cylinder))
	{
		ft_free_all_arr(line);
		parser_error("Invaild cylinder\n");
	}
	meta = singleton();
	obj = ft_malloc(sizeof(t_obj));
	obj->type = CY;
	obj->content.cylinder = cylinder;
	obj->next = NULL;
	objsadd_back(&meta->objs, obj);
}
