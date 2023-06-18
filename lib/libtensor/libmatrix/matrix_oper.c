/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:03:51 by jgo               #+#    #+#             */
/*   Updated: 2023/06/17 12:56:30 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tensor.h"

t_mat4	rotate(t_mat4 m, double radian, t_vec3 v)
{
	const	double c = cos(radian);
	const	double s = sin(radian);
	const 	t_vec3	axis = vec3_unit(v);
	const	t_vec3	tmp = vec3_scalar_multi(axis, 1 - c);
	t_mat3	rotate;
	t_mat4	result;

	rotate.a.x = c + tmp.x * axis.x;
	rotate.a.y = tmp.x * axis.y + s * axis.z;
	rotate.a.z = tmp.x * axis.z - s * axis.y;

	rotate.b.x = tmp.y * axis.x - s * axis.z;
	rotate.b.y = c + tmp.y * axis.y;
	rotate.b.z = tmp.y * axis.z + s * axis.x;

	rotate.c.x = tmp.z * axis.x + s * axis.y;
	rotate.c.y = tmp.z * axis.y - s * axis.x;
	rotate.c.z = c + tmp.z * axis.z;

	result.a = vec4_plus(vec4_plus(vec4_scalar_multi(m.a , rotate.a.x), vec4_scalar_multi(m.b, rotate.a.y)), vec4_scalar_multi(m.c, rotate.a.z));
	result.b = vec4_plus(vec4_plus(vec4_scalar_multi(m.a , rotate.b.x), vec4_scalar_multi(m.b, rotate.b.y)), vec4_scalar_multi(m.c, rotate.b.z));
	result.c = vec4_plus(vec4_plus(vec4_scalar_multi(m.a , rotate.c.x), vec4_scalar_multi(m.b, rotate.c.y)), vec4_scalar_multi(m.c, rotate.c.z));
	result.d = m.d;
	
	return (result);
}

t_mat4 vec4_multi(t_mat4 m1, t_mat4 m2)
{
    t_mat4 result;

    result.a.x = m1.a.x * m2.a.x + m1.a.y * m2.b.x + m1.a.z * m2.c.x + m1.a.w * m2.d.x;
    result.a.y = m1.a.x * m2.a.y + m1.a.y * m2.b.y + m1.a.z * m2.c.y + m1.a.w * m2.d.y;
    result.a.z = m1.a.x * m2.a.z + m1.a.y * m2.b.z + m1.a.z * m2.c.z + m1.a.w * m2.d.z;
    result.a.w = m1.a.x * m2.a.w + m1.a.y * m2.b.w + m1.a.z * m2.c.w + m1.a.w * m2.d.w;

    result.b.x = m1.b.x * m2.a.x + m1.b.y * m2.b.x + m1.b.z * m2.c.x + m1.b.w * m2.d.x;
    result.b.y = m1.b.x * m2.a.y + m1.b.y * m2.b.y + m1.b.z * m2.c.y + m1.b.w * m2.d.y;
    result.b.z = m1.b.x * m2.a.z + m1.b.y * m2.b.z + m1.b.z * m2.c.z + m1.b.w * m2.d.z;
    result.b.w = m1.b.x * m2.a.w + m1.b.y * m2.b.w + m1.b.z * m2.c.w + m1.b.w * m2.d.w;

    result.c.x = m1.c.x * m2.a.x + m1.c.y * m2.b.x + m1.c.z * m2.c.x + m1.c.w * m2.d.x;
    result.c.y = m1.c.x * m2.a.y + m1.c.y * m2.b.y + m1.c.z * m2.c.y + m1.c.w * m2.d.y;
    result.c.z = m1.c.x * m2.a.z + m1.c.y * m2.b.z + m1.c.z * m2.c.z + m1.c.w * m2.d.z;
    result.c.w = m1.c.x * m2.a.w + m1.c.y * m2.b.w + m1.c.z * m2.c.w + m1.c.w * m2.d.w;

    result.d.x = m1.d.x * m2.a.x + m1.d.y * m2.b.x + m1.d.z * m2.c.x + m1.d.w * m2.d.x;
    result.d.y = m1.d.x * m2.a.y + m1.d.y * m2.b.y + m1.d.z * m2.c.y + m1.d.w * m2.d.y;
    result.d.z = m1.d.x * m2.a.z + m1.d.y * m2.b.z + m1.d.z * m2.c.z + m1.d.w * m2.d.z;
    result.d.w = m1.d.x * m2.a.w + m1.d.y * m2.b.w + m1.d.z * m2.c.w + m1.d.w * m2.d.w;

    return result;
}
