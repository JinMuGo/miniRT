/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:48:14 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/08 16:48:29 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	vaildation_camera(t_camera cam)
{
	if (cam.type != CAM)
		return (false);
	if (!check_minus1_to_1(cam.normal_vec3.x)
		|| !check_minus1_to_1(cam.normal_vec3.y)
		|| !check_minus1_to_1(cam.normal_vec3.z))
		return (false);
	if (!check_0_to_180(cam.fov))
		return (false);
	return (true);
}

void	parse_camera(char **line)
{
	t_meta		*meta;
	t_camera	cam;

	if (ft_arrlen((void **)line) != 4)
		parser_error("Incorrect number of camera information\n");
	cam.type = CAM;
	cam.view_point = parse_point3(line[1]);
	cam.normal_vec3 = parse_vec3(line[2]);
	cam.fov = check_to_double(line[3]);
	if (!vaildation_camera(cam))
		parser_error("Invaild camera\n");
	meta = singleton();
	meta->camera = cam;
}
