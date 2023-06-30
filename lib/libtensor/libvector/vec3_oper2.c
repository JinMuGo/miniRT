/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_oper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:22:04 by jgo               #+#    #+#             */
/*   Updated: 2023/06/25 23:02:39 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tensor.h"

t_vec3	vec3_scalar_divide(t_vec3 vec3, double scalar)
{
	return (vec3_init(
			vec3.x * (1.0 / scalar),
			vec3.y * (1.0 / scalar),
			vec3.z * (1.0 / scalar)));
}

t_vec3	vec3_scalar_multi(t_vec3 vec3, double scalar)
{
	return (vec3_init(vec3.x * scalar, vec3.y * scalar, vec3.z * scalar));
}

t_vec3	vec3_scalar_minus(t_vec3 vec3, double scalar)
{
	return (vec3_init(vec3.x - scalar, vec3.y - scalar, vec3.z - scalar));
}
