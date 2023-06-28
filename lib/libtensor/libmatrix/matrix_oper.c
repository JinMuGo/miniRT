/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:23:38 by jgo               #+#    #+#             */
/*   Updated: 2023/06/26 14:59:23 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tensor.h"

void	mat3_transpose(t_mat3 *matrix)
{
	double temp;

	temp = matrix->a.y;
	matrix->a.y = matrix->b.x;
	matrix->b.x = temp;

	temp = matrix->a.z;
	matrix->a.z = matrix->c.x;
	matrix->c.x = temp;

	temp = matrix->b.z;
	matrix->b.z = matrix->c.y;
	matrix->c.y = temp;
}

t_vec3	mat3_vec3_multi(const t_mat3 *matrix, const t_vec3 *vec)
{
    const t_vec3 result = {
		matrix->a.x * vec->x + matrix->b.x * vec->y + matrix->c.x * vec->z,
		matrix->a.y * vec->x + matrix->b.y * vec->y + matrix->c.y * vec->z,
		matrix->a.z * vec->x + matrix->b.z * vec->y + matrix->c.z * vec->z};

    return (result);
}