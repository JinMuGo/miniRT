/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:18:05 by jgo               #+#    #+#             */
/*   Updated: 2023/06/15 17:06:08 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "utils.h"
#include "render.h"

t_vec3	reflect(t_vec3 a, t_vec3 b)
{
	return (vec3_minus(a, vec3_scalar_multi(b, vec3_inner_product(a, b) * 2)));
}

bool	in_shadow(t_obj *objs, t_ray *light_ray, double light_len)
{
    t_record record;

    record.t = light_len;
    return (find_obj_in_pixel(objs, light_ray, &record));
}
