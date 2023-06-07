/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:48:39 by jgo               #+#    #+#             */
/*   Updated: 2023/06/07 16:19:19 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	vec3_init(double x, double y, double z)
{
	const t_vec3	vec3 = {x, y, z};

	return (vec3);
}

t_vec4	vec4_init(double x, double y, double z, double w)
{
	const t_vec4	vec4 = {x, y, z, w};

	return (vec4);
}
