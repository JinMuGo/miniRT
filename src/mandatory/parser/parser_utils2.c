/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:47:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/14 16:17:52 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	check_normal_vec(t_vec3 vector)
{
	if (!check_minus1_to_1(vector.x)
		|| !check_minus1_to_1(vector.y)
		|| !check_minus1_to_1(vector.z)
		|| (fabs(vector.x - 0.0) < EPSILON
			&& fabs(vector.y - 0.0) < EPSILON
			&& fabs(vector.z - 0.0) < EPSILON))
		return (false);
	return (true);
}
