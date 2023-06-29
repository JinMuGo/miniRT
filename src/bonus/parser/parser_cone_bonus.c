/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cone_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:36:50 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 13:49:33 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "utils_bonus.h"
#include "design_patterns_bonus.h"

static bool	vaildation_cone(t_cone *cone)
{
	if (cone->type != CO
		|| !check_normal_vec(cone->normal_vec3) || !check_rgb(&cone->rgb)
		|| cone->radius <= 0 || cone->height <= 0)
		return (false);
	return (true);
}

void	parser_cone(char **line)
{
	const int	len = ft_arrlen((void **)line);
	t_meta		*meta;
	t_cone		cone;
	t_obj		*obj;

	if (len != 6)
		error_handler(CO_ERR);
	cone.type = CO;
	cone.base_point = parser_vec3(line[1], POINT_ERR);
	cone.normal_vec3 = vec3_unit(parser_vec3(line[2], VEC_ERR));
	cone.radius = check_to_double(line[3]);
	cone.height = check_to_double(line[4]);
	cone.rgb = parser_vec3(line[5], VEC_ERR);
	if (!vaildation_cone(&cone))
	{
		ft_free_all_arr(line);
		error_handler(CO_ERR);
	}
	meta = singleton();
	obj = ft_malloc(sizeof(t_obj));
	obj->type = CO;
	obj->content.cone = cone;
	obj->next = NULL;
	objsadd_back(&meta->objs, obj);
}
