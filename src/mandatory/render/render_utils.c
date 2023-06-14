/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:03:17 by jgo               #+#    #+#             */
/*   Updated: 2023/06/13 18:05:49 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"

t_vec3	get_unit_normal_vec(t_vec3 a, t_vec3 b, double scalar)
{
	return (vec3_scalar_divide(vec3_minus(a, b), scalar));
}
