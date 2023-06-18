/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:20:25 by jgo               #+#    #+#             */
/*   Updated: 2023/06/18 17:36:59 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tensor.h"

double	vec3_square_length(t_vec3 vec3)
{
	return (vec3.x * vec3.x + vec3.y * vec3.y + vec3.z * vec3.z);
}

double	vec3_length(t_vec3 vec3)
{
	return (sqrt(vec3_square_length(vec3)));
}

t_vec3	vec3_unit(t_vec3 vec3)
{
	const double	length = vec3_length(vec3);

	return (vec3_init(vec3.x / length, vec3.y / length, vec3.z / length));
}

t_vec3	vec3_scale(t_vec3 vec3, float s)
{
	return (vec3_init(vec3.x * s, vec3.y * s, vec3.z * s));
}
