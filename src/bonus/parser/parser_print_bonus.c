/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:18:42 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/18 17:21:22 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "defs_bonus.h"
#include "design_patterns_bonus.h"

void	print_ambient(t_meta *meta)
{
	printf("===ambient===\n");
	printf("Type: %d\n", meta->ambient.type);
	printf("Ratio: %f\n", meta->ambient.ratio);
	printf("RGB: %f, %f, %f\n", meta->ambient.rgba.r, meta->ambient.rgba.g,
		meta->ambient.rgba.b);
}

void	print_camera(t_meta *meta)
{
	printf("===camera===\n");
	printf("Type: %d\n", meta->camera.type);
	printf("Point: %f, %f, %f\n", meta->camera.view_point.x,
		meta->camera.view_point.y, meta->camera.view_point.z);
	printf("Vec: %f, %f, %f\n", meta->camera.normal_vec3.x,
		meta->camera.normal_vec3.y, meta->camera.normal_vec3.z);
	printf("FOV: %f\n", meta->camera.fov);
}

void	print_light(t_meta *meta)
{
	t_list			*current;
	t_spot_light	*light;

	current = meta->spot_lights;
	printf("===light===\n");
	while (current != NULL)
	{
		light = (t_spot_light *)current->content;
		printf("Light point: %f, %f, %f\n", light->light_point.x,
			light->light_point.y, light->light_point.z);
		printf("Ratio: %f\n", light->ratio);
		printf("RGB: %f, %f, %f\n", light->rgba.r, light->rgba.g,
			light->rgba.b);
		current = current->next;
	}
}
