/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:00:17 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 10:01:08 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	vaildation_sphere(t_sphere *sphere)
{
	if (sphere->type != SP)
		return (false);
	if (!check_rgb(&sphere->rgb) || sphere->diameter <= 0)
		return (false);
	return (true);
}

void	parser_sphere(char **line)
{
	t_obj		*obj;
	t_sphere	sphere;

	if (ft_arrlen((void **)line) != 4)
		error_handler(SP_ERR);
	sphere.type = SP;
	sphere.center_point = parser_vec3(line[1], POINT_ERR);
	sphere.diameter = check_to_double(line[2]);
	sphere.radius = sphere.diameter / 2;
	sphere.rgb = parser_vec3(line[3], RGB_ERR);
	if (!vaildation_sphere(&sphere))
	{
		ft_free_all_arr(line);
		error_handler(SP_ERR);
	}
	obj = ft_malloc(sizeof(t_obj));
	obj->type = SP;
	obj->content.sphere = sphere;
	obj->next = NULL;
	objsadd_back(&singleton()->objs, obj);
}
