/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:08:27 by jgo               #+#    #+#             */
/*   Updated: 2023/06/17 12:53:02 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tensor.h"

t_mat4	mat4_init(t_vec4 a, t_vec4 b, t_vec4 c, t_vec4 d)
{
	const t_mat4 mat4 = {a, b, c, d};

	return (mat4);
}

t_mat4 mat4_init_one_val(double val)
{
	const t_vec4 vec4 = vec4_init(val, val, val, val);
	const t_mat4 mat4 = mat4_init(vec4, vec4, vec4, vec4);

	return (mat4);
}

t_mat3	mat3_init(t_vec3 a, t_vec3 b, t_vec3 c)
{
	const t_mat3 mat3 = {a, b, c};

	return (mat3);
}

t_mat3 mat3_init_one_val(double val)
{
	const t_vec3 vec3 = vec3_init(val, val, val);
	const t_mat3 mat3 = mat3_init(vec3, vec3, vec3);

	return (mat3);
}