/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:48:14 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 16:11:40 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	_vaildation_camera(t_camera cam)
{
	if (cam.type != CAM
		|| !check_normal_vec(cam.normal_vec3) || !check_0_to_180(cam.fov))
		return (false);
	return (true);
}

void	parser_camera(char **line)
{
	t_meta		*meta;
	t_camera	cam;

	if (ft_arrlen((void **)line) != 4)
		error_handler(CAM_ERR);
	cam.type = CAM;
	cam.view_point = parser_vec3(line[1], POINT_ERR);
	cam.normal_vec3 = vec3_unit(parser_vec3(line[2], VEC_ERR));
	cam.fov = check_to_double(line[3]);
	cam.pos = cam.view_point;
	cam.forward = vec3_scalar_multi(cam.normal_vec3, -1);
	cam.pitch = asin(-cam.forward.y);
	cam.yaw = atan2(cam.forward.x, cam.forward.z);
	meta = singleton();
	if (!_vaildation_camera(cam) || meta->camera.type == CAM)
	{
		ft_free_all_arr(line);
		error_handler(CAM_ERR);
	}
	meta->camera = cam;
}
