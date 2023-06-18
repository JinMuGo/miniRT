/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:54:01 by jgo               #+#    #+#             */
/*   Updated: 2023/06/17 12:55:09 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tensor.h"

t_vec4	vec4_plus(t_vec4 a, t_vec4 b)
{
	return (vec4_init(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w));
}

t_vec4	vec4_scalar_multi(t_vec4 vec4, double scalar)
{
	return (vec4_init(vec4.x * scalar, vec4.y * scalar, vec4.z * scalar, vec4.w * scalar));
}

