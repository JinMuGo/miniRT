/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:18:05 by jgo               #+#    #+#             */
/*   Updated: 2023/06/21 13:55:37 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs_bonus.h"
#include "minirt_bonus.h"
#include "utils_bonus.h"
#include "render_bonus.h"

t_vec3	reflect(t_vec3 a, t_vec3 b)
{
	return (vec3_minus(vec3_scalar_multi(b, vec3_inner_product(a, b) * 2), a));
}

bool	in_shadow(t_obj *objs, t_record *record, t_vec3 light_dir,
		double light_len)
{
	const t_ray	light_ray = ray_init(vec3_plus(record->point, \
			vec3_scalar_multi(record->normal_vec3, EPSILON)), light_dir);
	t_record	new_record;

	new_record.t = light_len;
	return (find_obj_in_pixel(objs, (t_ray *)&light_ray, &new_record));
}
