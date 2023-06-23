/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:00:17 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/20 16:05:10 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	vaildation_sphere(t_sphere *sphere)
{
	if (sphere->type != SP)
		return (false);
	if (!check_rgba(sphere->rgba) || sphere->diameter <= 0)
		return (false);
	return (true);
}

void	parser_sphere(char **line)
{
	t_meta		*meta;
	t_obj		*obj;
	t_sphere	sphere;

	if (ft_arrlen((void **)line) != 4)
		error_handler(SP_ERR);
	sphere.type = SP;
	sphere.center_point = parser_point3(line[1]);
	sphere.diameter = check_to_double(line[2]);
	sphere.radius = sphere.diameter / 2;
	sphere.rgba = parser_rgba(line[3]);
	if (!vaildation_sphere(&sphere))
	{
		ft_free_all_arr(line);
		error_handler(SP_ERR);
	}
	meta = singleton();
	obj = ft_malloc(sizeof(t_obj));
	obj->type = SP;
	obj->content.sphere = sphere;
	obj->next = NULL;
	objsadd_back(&meta->objs, obj);
}
