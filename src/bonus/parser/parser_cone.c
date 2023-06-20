/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:36:50 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/20 16:09:21 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	vaildation_cone(t_cone *cone)
{
	if (cone->type != CO)
		return (false);
	if (!check_normal_vec(cone->normal_vec3) || !check_rgba(cone->rgba)
		|| cone->radius <= 0 || cone->height <= 0)
		return (false);
	return (true);
}

void	parser_cone(char **line)
{
	t_meta		*meta;
	t_cone		cone;
	t_obj		*obj;

	if (ft_arrlen((void **)line) != 6)
		error_handler(CY_ERR);
	cone.type = CO;
	cone.center_point = parser_point3(line[1]);
	cone.normal_vec3 = vec3_unit(parser_vec3(line[2]));
	cone.radius = check_to_double(line[3]);
	cone.height = check_to_double(line[4]);
	cone.rgba = parser_rgba(line[5]);
	if (!vaildation_cone(&cone))
	{
		ft_free_all_arr(line);
		printf("cone\n");
		error_handler(CY_ERR);
	}
	meta = singleton();
	obj = ft_malloc(sizeof(t_obj));
	obj->type = CO;
	obj->content.cone = cone;
	obj->next = NULL;
	objsadd_back(&meta->objs, obj);
}
