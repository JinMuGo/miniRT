/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_oper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:22:04 by jgo               #+#    #+#             */
/*   Updated: 2023/06/10 20:28:13 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	vec3_scalar_divide(t_vec3 vec3, double scalar)
{
	return (vec3_init(vec3.x / scalar, vec3.y / scalar, vec3.z / scalar));
}
