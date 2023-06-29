/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:00:17 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 16:13:28 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	_vaildation_sphere(t_sphere *sphere)
{
	if (sphere->type != SP)
		return (false);
	if (!check_rgb(&sphere->rgb) || sphere->diameter <= 0)
		return (false);
	return (true);
}

static inline void	_set_sphere_info(t_sphere *sphere, char **line)
{
	sphere->type = SP;
	sphere->center_point = parser_vec3(line[1], POINT_ERR);
	sphere->diameter = check_to_double(line[2]);
	sphere->radius = sphere->diameter / 2;
	sphere->rgb = parser_vec3(line[3], RGB_ERR);
}

void	parser_sphere(char **line)
{
	const int		len = ft_arrlen((void **)line);
	t_obj			*obj;
	t_sphere		sphere;

	if (!(len == 4))
		error_handler(SP_ERR);
	_set_sphere_info(&sphere, line);
	if (!_vaildation_sphere(&sphere))
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
