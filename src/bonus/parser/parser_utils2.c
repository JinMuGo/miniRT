/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:47:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/22 15:12:07 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	check_normal_vec(t_vec3 vector)
{
	if (!check_minus1_to_1(vector.x) || !check_minus1_to_1(vector.y)
		|| !check_minus1_to_1(vector.z) || (vector.x == 0 && vector.y == 0
			&& vector.z == 0))
		return (false);
	return (true);
}

bool	vaildation_option(t_obj_option *option)
{
	if (option == NULL)
		return (true);
	if (option->type == CB)
	{
		if (option->op.cb.degree < 0 || !check_rgba(option->op.cb.rgba)
			|| !check_0_to_1(option->op.cb.scale_s)
			|| !check_0_to_1(option->op.cb.scale_t))
			return (false);
	}
	return (true);
}