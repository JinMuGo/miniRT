/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:00:17 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 13:49:33 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "utils_bonus.h"
#include "design_patterns_bonus.h"

static bool	vaildation_sphere(t_sphere *sphere)
{
	if (sphere->type != SP)
		return (false);
	if (!check_rgb(&sphere->rgb) || sphere->diameter <= 0)
		return (false);
	return (true);
}

static inline void	set_sphere_info(t_sphere *sphere, char **line)
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
	t_obj_option	*option;
	t_obj			*obj;
	t_sphere		sphere;

	if (!(len == 4 || len == 6 || len == 8 || len == 9))
		error_handler(SP_ERR);
	set_sphere_info(&sphere, line);
	if (line[4])
		option = option_allocator(line, 4, SP_ERR);
	else
		option = NULL;
	if (!vaildation_sphere(&sphere) || !vaildation_option(option))
	{
		ft_free_all_arr(line);
		error_handler(SP_ERR);
	}
	obj = ft_malloc(sizeof(t_obj));
	obj->type = SP;
	obj->content.sphere = sphere;
	obj->option = option;
	obj->next = NULL;
	objsadd_back(&singleton()->objs, obj);
}
