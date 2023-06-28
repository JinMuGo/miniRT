/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:47:30 by jgo               #+#    #+#             */
/*   Updated: 2023/06/28 18:01:43 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tensor.h"

static inline t_vec3	_judge_up_vector(t_vec3 vec)
{
	if (is_vec3_same(vec, vec3_init(0, 1, 0)))
		return (vec3_init(0, 0, 1));
	if (is_vec3_same(vec, vec3_init(0, -1, 0)))
		return (vec3_init(0, 0, -1));
	return (vec3_init(0, 1, 0));
}

void	set_ab_axis_from_c(t_vec3 *a, t_vec3 *b, const t_vec3 *c)
{
	const t_vec3 up = _judge_up_vector(*c);

	*a = vec3_unit(vec3_cross_product(up, *c));
	*b = vec3_unit(vec3_cross_product(*c, *a));
}
