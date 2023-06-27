/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:51:52 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/26 20:43:46 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	vaildation_plane(t_plane *plane)
{
	if (plane->type != PL)
		return (false);
	if (!check_normal_vec(plane->normal_vec3) || !check_rgba(plane->rgba))
		return (false);
	return (true);
}

void	parser_plane(char **line)
{
	const int		len = ft_arrlen((void **)line);
	t_obj_option	*option;
	t_plane			plane;
	t_obj			*obj;
	int				idx;

	if (!(len == 4 || len == 6 || len == 8 || len == 9))
		error_handler(PL_ERR);
	idx = 1;
	plane.type = PL;
	plane.point = parser_point3(line[1]);
	plane.normal_vec3 = vec3_unit(parser_vec3(line[2]));
	plane.rgba = parser_rgba(line[3]);
	if (line[4])
		option = option_allocator(line, 4, PL_ERR);
	else
		option = NULL;
	if (!vaildation_plane(&plane) || !vaildation_option(option))
	{
		ft_free_all_arr(line);
		error_handler(PL_ERR);
	}
	obj = ft_malloc(sizeof(t_obj));
	obj->type = PL;
	obj->content.plane = plane;
	obj->option = option;
	obj->next = NULL;
	objsadd_back(&singleton()->objs, obj);
}
