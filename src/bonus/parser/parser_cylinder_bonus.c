/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cylinder_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:50:54 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 13:49:33 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "utils_bonus.h"
#include "design_patterns_bonus.h"

static bool	vaildation_cylinder(t_cylinder *cylinder)
{
	if (cylinder->type != CY
		|| !check_normal_vec(cylinder->normal_vec3)
		|| !check_rgb(&cylinder->rgb)
		|| cylinder->diameter <= 0
		|| cylinder->height <= 0)
		return (false);
	return (true);
}

static inline void	set_cylinder_info(t_cylinder *cylinder, char **line)
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
	t_obj_option	*option;
	t_cylinder		cylinder;
	t_obj			*obj;

	if (!(len == 6 || len == 8 || len == 10 || len == 11))
		error_handler(CY_ERR);
	set_cylinder_info(&cylinder, line);
	if (line[6])
		option = option_allocator(line, 6, CY_ERR);
	else
		option = NULL;
	if (!vaildation_cylinder(&cylinder) || !vaildation_option(option))
	{
		ft_free_all_arr(line);
		error_handler(CY_ERR);
	}
	obj = ft_malloc(sizeof(t_obj));
	obj->type = CY;
	obj->content.cylinder = cylinder;
	obj->option = option;
	obj->next = NULL;
	objsadd_back(&singleton()->objs, obj);
}
