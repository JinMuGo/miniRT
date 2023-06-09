/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/06/09 14:54:40 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "design_patterns.h"
#include "utils.h"
#include "parser.h"

void print_ambient(t_meta *meta) {
	printf("===ambient===\n");
	printf("Type: %d\n", meta->ambient.type);
	printf("Ratio: %f\n", meta->ambient.ratio);
	printf("RGB: %f, %f, %f\n", meta->ambient.rgb.r, meta->ambient.rgb.g, meta->ambient.rgb.b);
}

void print_camera(t_meta *meta) {
	printf("===camera===\n");
	printf("Type: %d\n", meta->camera.type);
	printf("Point: %f, %f, %f\n", meta->camera.view_point.x, meta->camera.view_point.y, meta->camera.view_point.z);
	printf("Vec: %f, %f, %f\n", meta->camera.normal_vec3.x, meta->camera.normal_vec3.y, meta->camera.normal_vec3.z);
	printf("FOV: %f\n", meta->camera.fov);
}

void print_light(t_meta *meta) {
	printf("===light===\n");
	t_list *current = meta->spot_lights;
	while (current != NULL) {
		t_spot_light *light = (t_spot_light *)current->content;
		printf("Light point: %f, %f, %f\n", light->light_point.x, light->light_point.y, light->light_point.z);
		printf("Ratio: %f\n", light->ratio);
		printf("RGB: %f, %f, %f\n", light->rgb.r, light->rgb.g, light->rgb.b);
		free(light);
		current = current->next;
	}
}

int main(void) {
	char *str1 = "A 0.2 255,255,255";
	char *str2 = "C -50.0,0,20 0,0,1 70";
	char *s_light = "L -40.0,50.0,0.0 0.6 10,0,255";

	char **temp1 = ft_split_whitespace(str1);
	char **temp2 = ft_split_whitespace(str2);
	char **l_temp = ft_split_whitespace(s_light);

	printf("%s\n", str1);
	parser_ambient(temp1);
	printf("%s\n", str2);
	parser_camera(temp2);
	printf("%s\n", s_light);
	parser_light(l_temp);

	t_meta *meta = singleton();

	print_ambient(meta);
	print_camera(meta);
	print_light(meta);

	free(meta);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	t_meta	*meta;

// 	(void)ac;
// 	(void)av;
// 	meta = singleton();
// 	mlx_image_to_window(meta->mlx_assets.mlx, meta->mlx_assets.img, 0, 0);
// 	mlx_loop_hook(meta->mlx_assets.mlx, hooks, meta);
// 	mlx_loop(meta->mlx_assets.mlx);
// 	return (EXIT_SUCCESS);
// }