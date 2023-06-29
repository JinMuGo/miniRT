/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_print_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:18:42 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 13:37:35 by jgo              ###   ########.fr       */
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
	printf("RGB: %f, %f, %f\n", meta->ambient.rgb.x, meta->ambient.rgb.y,
		meta->ambient.rgb.z);
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
		printf("RGB: %f, %f, %f\n", light->rgb.x, light->rgb.y,
			light->rgb.z);
		current = current->next;
	}
}
