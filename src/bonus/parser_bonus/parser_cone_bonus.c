/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cone_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:36:50 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/30 15:20:42 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "utils_bonus.h"
#include "render_bonus.h"
#include "design_patterns_bonus.h"

static bool	vaildation_cone(t_cone *cone)
{
	if (cone->type != CO
		|| !check_normal_vec(cone->normal_vec3) || !check_rgb(&cone->rgb)
		|| cone->radius <= 0 || cone->height <= 0)
		return (false);
	return (true);
}

static inline void	_set_cone_info(t_cone *cone, char **line)
{
	cone->type = CO;
	cone->base_point = parser_vec3(line[1], POINT_ERR);
	cone->normal_vec3 = vec3_unit(parser_vec3(line[2], VEC_ERR));
	cone->radius = check_to_double(line[3]);
	cone->height = check_to_double(line[4]);
	cone->rgb = parser_vec3(line[5], RGB_ERR);
}

static inline t_obj	*_set_obj_info(t_cone cone, t_obj_option *option)
{
	t_obj			*obj;

	obj = ft_malloc(sizeof(t_obj));
	obj->type = CO;
	obj->content.cone = cone;
	obj->get_t = get_cone_dist;
	obj->set_r = set_cone_record;
	obj->option = option;
	obj->next = NULL;
	return (obj);
}

void	parser_cone(char **line)
{
	const int		len = ft_arrlen((void **)line);
	t_obj_option	*option;
	t_cone			cone;

	if (!(len == 6 || len == 11))
		error_handler(CO_ERR);
	_set_cone_info(&cone, line);
	option = option_allocator(line, 6, CO_ERR);
	if (!vaildation_cone(&cone) || !vaildation_option(option)
		|| (option && option->type == TX))
	{
		ft_free_all_arr(line);
		error_handler(CO_ERR);
	}
	objsadd_back(&singleton()->objs, _set_obj_info(cone, option));
}
