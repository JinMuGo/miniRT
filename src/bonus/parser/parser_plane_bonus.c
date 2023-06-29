/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:51:52 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 14:43:39 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "utils_bonus.h"
#include "design_patterns_bonus.h"

static bool	vaildation_plane(t_plane *plane)
{
	if (plane->type != PL
		|| !check_normal_vec(plane->normal_vec3)
		|| !check_rgba(plane->rgba))
		return (false);
	return (true);
}

static inline void	set_plane_info(t_plane *plane, char **line)
{
	plane->type = PL;
	plane->point = parser_point3(line[1]);
	plane->normal_vec3 = vec3_unit(parser_vec3(line[2]));
	plane->rgba = parser_rgba(line[3]);
}

void	parser_plane(char **line)
{
	const int		len = ft_arrlen((void **)line);
	t_obj_option	*option;
	t_plane			plane;
	t_obj			*obj;

	if (!(len == 4 || len == 6 || len == 8 || len == 9))
		error_handler(PL_ERR);
	set_plane_info(&plane, line);
	option = option_allocator(line, 4, PL_ERR);
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
